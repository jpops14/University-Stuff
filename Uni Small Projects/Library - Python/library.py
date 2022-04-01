import sqlite3
import sys
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Table, Column, Integer, ForeignKey, String, DateTime
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker, relationship, validates
import sqlalchemy
from sqlalchemy.sql.expression import null
from sqlalchemy.sql.sqltypes import NULLTYPE
from sqlalchemy.sql.visitors import TraversibleType


# database functions and classes

Base = declarative_base()

BookTag = Table('BookTag',
                Base.metadata,
                Column('id', Integer, primary_key=True),
                Column('BookId', Integer, ForeignKey('Book.book_id')),
                Column('Tagline', String(20), ForeignKey('Tag.tag')))


class Genre(Base):
    __tablename__ = 'Genre'

    genre = Column(String(20), nullable=False, primary_key=True)
    books = relationship('Book')


class Book(Base):
    __tablename__ = 'Book'

    book_id = Column(Integer, primary_key=True)
    title = Column(String(40), nullable=False)
    author = Column(String(40), nullable=False)
    year = Column(Integer, nullable=False)
    # one to many, Book can be borrowed only by one person at a time
    posession = Column(Integer, ForeignKey('Person.person_id'))
    genre = Column(String(20), ForeignKey('Genre.genre'))
    book_tags = relationship('Tag', secondary=BookTag)


class Tag(Base):
    __tablename__ = 'Tag'

    tag = Column(String(20), primary_key=True)
    books = relationship('Book', secondary=BookTag, overlaps="book_tags")


class Person(Base):
    __tablename__ = 'Person'

    person_id = Column(Integer, primary_key=True)
    name = Column(String(40), nullable=False)
    email = Column(String(40), nullable=False)
    # one to many, a Person can borrow multiple books
    borrowed = relationship('Book')


def addTag(session, tagline):
    tagres = session.query(Tag).filter(Tag.tag == tagline).first()
    if tagres is not None:
        return tagres
    tagres = Tag(tag=tagline)
    session.add(tagres)
    return tagres


def addBook(session, btitle, bauthor, byear, bgenre, btaglist):
    if(session.query(Genre).filter(Genre.genre == bgenre).first() is None):
        newgenre = Genre(genre=bgenre)
        session.add(newgenre)
    newBook = Book(title=btitle, author=bauthor, year=byear, genre=bgenre)
    taglist = btaglist.split("#")
    for x in taglist:
        newtag = addTag(session, x)
        newBook.book_tags.append(newtag)
    session.add(newBook)

    session.commit()
    return True


def addPerson(session, fname, femail):
    newPerson = Person(name=fname, email=femail)
    session.add(newPerson)
    session.commit()
    return True


def removePerson(session, id):
    person = session.query(Person).filter(Person.person_id == id).first()
    if person is None:
        return
    person.borrowed = []
    session.commit()
    session.delete(person)
    session.commit()


def removeBook(session, id):
    book = session.query(Book).filter(Book.book_id == id).first()
    book.possesion = None
    session.commit()
    session.delete(book)
    session.commit()


def returnBook(session, bid):
    book = session.query(Book).filter(Book.book_id == bid).first()
    book.posession = None
    session.commit()


def getPerson(session, pid):
    person = session.query(Person).filter(Person.person_id == pid).first()
    res = "ID: " + str(person.person_id) + "\nNAME: " + person.name + \
        "\nEMAIL: " + person.email + "\nBORROWED BOOKS:\n"
    for book in person.borrowed:
        res += "  " + book.title + "\n"
    return res


def getBook(session, bid):
    book = session.query(Book).filter(Book.book_id == bid).first()
    res = ("ID: " + str(book.book_id) + "\nTITLE: " + book.title+"\nAUTHOR: " +
           book.author + "\nYEAR: " + str(book.year) + "\nGENRE: " +
           str(book.genre) + "\nIN POSESSION OF: " + str(book.posession) +
           "\nTAGS:\n")

    for tag in book.book_tags:
        res += "  " + tag.tag + "\n"

    res = res
    return res


def borrowBook(session, clientid, bookid):
    book = session.query(Book).filter(Book.book_id == bookid).first()
    if book.posession is not None and book.posession != sqlalchemy.sql.null:
        return False
    book.posession = clientid
    session.commit()
    return True


def openSession():
    db = sqlite3.connect('temp.db')
    engine = create_engine('sqlite:///temp.db', echo=False)
    Base.metadata.create_all(engine)
    Session = sessionmaker(bind=engine)
    s = Session()
    return s


if __name__ == "__main__":
    s = openSession()
    id =s.query(Book).first().book_id
    print(getBook(s,id))
    
