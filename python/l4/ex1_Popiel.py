import operator
import timeit

# cryptarithm format: [a,[b,c,d]]
# where: a is an operator passed as string, for example: '+' for adding operation
#        b and c are arguments to which the operator is applied
#        c is the result of the operation
#        b and c are strings containing capital letters

#    KTO
# +  KOT
# --------
#    TOK
# This test will be represented as: ['+',["KTO","KOT","TOK"]]

# this function takes a dictionary (potential solution for cryptarithm, pairing cap letters to digits)
# and translates string containing letters to a string which represents a number
def translate(dict,word):         
    return  ''.join(map(str, [dict[i]for i in word]))

# this function checks if given potential solution is correct by checking if the equation is true
def check_sol(op,sol,x,y,z):
    nx=translate(sol,x)
    ny=translate(sol,y)
    nz=translate(sol,z)
    # important detail: we don't allow leading zeroes in our solutions
    if(nx[0]=='0' or ny[0]=='0' or nz[0]=='0'):
        return False
    nx=int(nx)
    ny=int(ny)
    nz=int(nz)    
    if (op(nx,ny)==nz):
        return sol
    return False


# brute force program checking all possible (up to 10! = 3628800 for 10 different letters)
# configurations of associated digits for present letters
# If a solution exists, it is returned in form of a python dictionary, which
# contains associations between letters and digits
def solve_cryptarithm(crypt):
    opdict={
        '+': operator.add,
        '-': operator.sub,
        '*': operator.mul
    }
    #processing input
    op=opdict[crypt[0]]
    x=list(crypt[1][0])
    y=list(crypt[1][1])
    z=list(crypt[1][2])
   
    #preparing data before recursively searching for solution
    #filtering out the letters that dont appear in given words

    ltrs=[chr(i) for i in range(65,91) if (chr(i) in x or chr(i) in y or chr(i) in z)]
    digits=[i for i in range(0,10)]

    #initializing an empty dictionary, which will be used to store the solution
    dict={}
    #starting backtracking search for solution

    return seek_sol(dict,digits,ltrs,op,x,y,z)

def seek_sol(dict,digits,ltrs,op,x,y,z):
    #if every letter has been assigned with a digit, we have a complete potential solution
    #which has to be checked
    if(not ltrs):
        return check_sol(op,dict,x,y,z)
    letter=ltrs[0]                 #Picking a letter which hasn't been assigned with a number yet
    for i in digits:               #looping through availaible digits (not assigned to a letter yet)
        dict[letter]=i
        newdigs=digits[:]
        newdigs.remove(i)          #recursively invoking the function with added assocation between letter and i
        res=seek_sol(dict,newdigs,ltrs[1:],op,x,y,z)
        if(res!=False):
            return res
        dict.pop(letter)
    return False                   #checked all options extended from given dict; none were viable

# basic tests
print("""1st example: Solution for: 
     SEND  
 +   MORE  
----------
    MONEY""")
   
print(solve_cryptarithm(['+',["SEND","MORE","MONEY"]]))
print("""2nd example: Solution for: 
     SESESESESESESESESESE 
 +   ZFZFZFZFZFZFZFZFZFZF
--------------------------
     GDGDGDGDGDGDGDGDGDGD""")
   
print(solve_cryptarithm(['+',["SESESESESESESESESESE","ZFZFZFZFZFZFZFZFZFZF","GDGDGDGDGDGDGDGDGDGD"]]))
print("""3rd example: Solution for: 
     KIOTO
 +   OSAKA
--------------------------
     TOKIO""")
   
print(solve_cryptarithm(['+',["KIOTO","OSAKA","TOKIO"]]))


# setup for timed tests

setu = '''from __main__ import solve_cryptarithm
from __main__ import check_sol
from __main__ import translate
from __main__ import seek_sol'''

timesnippet1='''solve_cryptarithm(['+',["SEND","MORE","MONEY"]])'''
timesnippet2='''solve_cryptarithm(['+',["SESESESESESESESESESE","ZFZFZFZFZFZFZFZFZFZF","GDGDGDGDGDGDGDGDGDGD"]])'''
timesnippet3='''solve_cryptarithm(['+',["KIOTO","OSAKA","TOKIO"]])'''
#time tests execution
print(f"1st example time: {timeit.timeit(setup=setu, stmt=timesnippet1,number=1)}")
print(f"2nd example time: {timeit.timeit(setup=setu, stmt=timesnippet2,number=1)}")
print(f"3rd example time: {timeit.timeit(setup=setu, stmt=timesnippet3,number=1)}")


# checking whether a single solution is correct is linearly dependent on word lengths;
# running time isn't corelated only to input lenght, because number of unique letters in given
# criptarithm is a big factor 
# worst case scenario - complexity is O((n+m)10!)