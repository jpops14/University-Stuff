import os

print("adding 3 friends to database: John, Paul and Dom")
os.system('python3 ex1_Popiel.py --add Friend name=John email=john@domain.com')
os.system('python3 ex1_Popiel.py --add Friend name=Paul email=paul@domain.com')
os.system('python3 ex1_Popiel.py --add Friend name=Dom email=dom@domain.com')
print("adding 3 books to database: some book, another book, and boring book")
os.system('python3 ex1_Popiel.py --add Book title=some_book author=well_known_author year=2007')
os.system('python3 ex1_Popiel.py --add Book title=another_book author=less_known_author year=2012')
os.system('python3 ex1_Popiel.py --add Book title=boring_book author=boring_author year=2003')
print("John borrows some book")
os.system('python3 ex1_Popiel.py --borrow John some_book')
print("Paul attempts to borrow the same book")
os.system('python3 ex1_Popiel.py --borrow Paul some_book')
print("Paul borrows another book and boring book")
os.system('python3 ex1_Popiel.py --borrow Paul another_book')
os.system('python3 ex1_Popiel.py --borrow Paul boring_book')
print('lets display current state of friends table:')
os.system('python3 ex1_Popiel.py --show Friend')
print('lets display current state of books table:')
os.system('python3 ex1_Popiel.py --show Book')
print("John returns some book, lets see friends table:")
os.system('python3 ex1_Popiel.py --return some_book')
os.system('python3 ex1_Popiel.py --show Friend')
print("Dom borrows some_book")
os.system('python3 ex1_Popiel.py --borrow Dom some_book')
os.system('python3 ex1_Popiel.py --show Friend')
