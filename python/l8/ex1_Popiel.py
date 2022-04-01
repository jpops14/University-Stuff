import sqlite3
import sys
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Table, Column, Integer,ForeignKey, String, DateTime
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker, relationship, validates
import sqlalchemy
from sqlalchemy.sql.expression import null
from sqlalchemy.sql.sqltypes import NULLTYPE
from sqlalchemy.sql.visitors import TraversibleType


Base= declarative_base()

class Book(Base):
    __tablename__ = 'Book'

    title = Column(String(40), primary_key=True, nullable=False)
    author = Column(String(40), nullable=True)
    year = Column(Integer, nullable=True)
    posession = Column(String(40),ForeignKey('Friend.name'))   #one to many, Book can be borrowed only by one person at a time


class Friend(Base):
    __tablename__ = 'Friend'
    #id = Column(Integer, primary_key=True,nullable=False)
    name = Column(String(40), primary_key=True,nullable=False) 
    email = Column(String(40),nullable=False)
    borrowed = relationship('Book')                  #one to many, a Friend can borrow multiple books

    @validates('email')
    def validate_email(self, key, value):
        assert '@' in value
        return value

def addBook(session, attrs):
    btitle = None
    bauthor = None
    byear = None
    for x in attrs:
        attr=x.replace("_"," ")
        if(attr.startswith("title=")):
            btitle=attr[6:]
        if(attr.startswith("author=")):
            bauthor=attr[7:]
        if(attr.startswith("year=")):
            byear=attr[5:]
    newBook = Book(title=btitle,author=bauthor,year=byear)
    session.add(newBook)
    session.commit()


def addFriend(session,attrs):
    fname = None
    femail = None
    for x in attrs:
        attr=x.replace("_"," ")
        if(attr.startswith("name=")):
            fname=attr[5:]
        if(attr.startswith("email=")):
            femail=attr[6:]
    newFriend=Friend(name=fname,email=femail)
    session.add(newFriend)
    session.commit()

def borrowBook(session,args):
    pass

def returnBook(session,booktitle):
    btitle = booktitle.replace("_"," ")
    book = session.query(Book).filter(Book.title == btitle).first()
    book.posession = None
    session.commit()

def printFriends(session):
    #print("in test")
    friends=session.query(Friend).all()
    for x in friends:
        print("NAME: " + x.name + " EMAIL: " + x.email + " BORROWED BOOKS:{")
        for book in x.borrowed:
            print(book.title)
        print("}")

def printBooks(session):
    books=session.query(Book).all()
    for x in books:
        print("TITLE: "+x.title+" AUTHOR: "+x.author+ " YEAR: " + str(x.year) + " IN POSESSION OF: " + str(x.posession))

def borrowBook(session, friend_name, book_title):
    btitle = book_title.replace("_"," ")
    fname = friend_name.replace("_"," ")
    book = session.query(Book).filter(Book.title == btitle).first()
    if book.posession!=None and book.posession!=sqlalchemy.sql.null:
        print("This book is not available")
        return
    book.posession=fname
    session.commit()




# database preparation 
db = sqlite3.connect('temp.db')
engine = create_engine('sqlite:///temp.db', echo=False)
Base.metadata.create_all(engine)
Session = sessionmaker(bind=engine)
s = Session()

# accepted commands : --add Friend ...(<attribute=<value>)...
#                     --add Book   ...(<attribute=<value>)...
#                     --borrow ...<Friend name> <book title>...
#                     --return ...<book title>...
#                     --show <table name> (Friend/Book)
# disclaimer: all names,titles etc. on input should have "_" characters instead of spaces, they will later be replaced by proper spaces
# we assume that all friends have unique names and all books have unique names (no duplicates of books)
# removing books and friends has not been implemented (even though it is trivial) 
# because friends and books are forever

args=sys.argv[1:]
command=args[0]

if command=='--add':
    args=args[1:]
    type=args[0]
    if type=='Friend':
        addFriend(s,args[1:])
    elif(type=='Book'):
        addBook(s,args[1:])
    else:
        print("invalid <--add> argument")
elif command=='--return':
    returnBook(s,args[1])
elif command=='--show':
    type=args[1]
    if type=='Friend':
        printFriends(s)
    elif type=="Book":
        printBooks(s)
    else:
        print("invalid <--show> argument")
elif command=='--borrow':
    borrowBook(s,args[1],args[2])
else:
    print("invalid database command")




# saving changes
s.close()

