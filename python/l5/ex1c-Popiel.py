import operator
#custom exceptions
class ExprError(Exception):
    """Expression specific error:"""
    pass
class DivByZeroError(ExprError):
    """Division by zero is not allowed"""
    pass
class UnknownVarError(ExprError):
    """Variable has not been assigned with any value"""
    pass
class ConstantError(ExprError):
    """Given constant is not a number"""
    pass




# we assume that for evaluation, variables values are given in a dictionary object
class Expression:
    def __init__(self,x):
        self.x=x
    def __add__(self,other):
        return Add(self,other)
    def __mul__(self,other):
        return Times(self,other)
    def __sub__(self,other):
        return Substract(self,other)
    def __truediv__(self,other):
        return Divide(self,other)
    @staticmethod
    def Derivative(x):
        return x.derivative()

    

#classess variable and constant are simple extensions of base class Expression
class Variable(Expression):
    def __init__(self,x):
        super().__init__(x)
    def evaluate(self, variables):
        if self.x in variables:
            return variables[self.x]
        else:
            raise UnknownVarError
    def __str__(self):
        return self.x
    def derivative(self):
        return Constant(1)

class Constant(Expression):
    def __init__(self,x):
        if type(x) == int or type(x) == float:
            super().__init__(x)
        else:
            raise ConstantError
    def evaluate(self, variables):  
        return self.x
    def __str__(self):
        return str(self.x)
    def derivative(self):
        return Constant(0)          

# Binop secondary base class includes methods shared by binary operator classes (similar evaluation and
# conversion to string
class Binop(Expression):
    #static dictionary for unified evaluation method
    operators={"+": operator.add,"-": operator.sub,"*": operator.mul, "/": operator.truediv}
    def __init__(self,x,y,op):
        super().__init__(x)
        self.y=y
        self.op=op
   
    def evaluate(self, variables):
        tempx=self.x.evaluate(variables)
        tempy=self.y.evaluate(variables)
        if tempy==0 and self.op=="/":
            raise DivByZeroError
        else:
            return Binop.operators[self.op](tempx,tempy)

    # extremely naive and simple because, frankly, i am really behind my schedule;
    # too many brackets is better than not enough brackets
    def __str__(self):
        tempx=str(self.x)
        tempy=str(self.y)
        tempx="("+tempx+")"
        tempy="("+tempy+")"
 
        return tempx+" "+self.op+" "+tempy
        


class Times(Binop):
    def __init__(self,x,y):
        super().__init__(x,y,"*")
    def derivative(self):
        return Add(Times(self.x.derivative(),self.y),Times(self.x,self.y.derivative()))  

class Divide(Binop):
    def __init__(self,x,y):
        super().__init__(x,y,"/")
    def derivative(self):
        return Divide(Substract(Times(self.x.derivative(),self.y),Times(self.x,self.y.derivative())),Times(self.y,self.y))

# classess Add and Substract are short in definition because they are inheriting
# methods defined in Binop
class Add(Binop):
    def __init__(self,x,y):
        super().__init__(x,y,"+")
    def derivative(self):
        return Add(self.x.derivative(),self.y.derivative())


class Substract(Binop):
    def __init__(self,x,y):
        super().__init__(x,y,"-")
    def Derivative(self):
        return Substract(self.x.derivative(),self.y.derivative())    

# Polynomial for simple and readable testing

x3=Times(Constant(5),Times(Times(Variable("x"),Variable("x")),Variable("x")))
x2=Times(Constant(7),Times(Variable("x"),Variable("x")))
x1=Times(Constant(2),Variable("x"))
x0=Constant(9)

polynomial=Add(x3,Add(x2,Add(x1,x0)))

print(polynomial)
#evaluation check
print("f(x)=5x^3 + 7x^2 + 2x + 9")
print("f(0)=")
print(polynomial.evaluate({"x":0}))
print("f(1)=")
print(polynomial.evaluate({"x":1}))
print("f(2)=")
print(polynomial.evaluate({"x":2}))
#check __add__ and __mul__
print("Test for + and * operators")
print(x0+x1) 
print(x1*x2)
# Derivative testing
print("Derivative of 5x^3 + 7x^2 + 2x + 9:")
print(Expression.Derivative(polynomial))
print("Derivative of 7x^2")
print(Expression.Derivative(x2))
print("Derivative of x^2/2x:")
print(Expression.Derivative(Divide(Times(Variable("x"),Variable("x")),Times(Constant(2),Variable("x")))))
# Some exception testing
try:
    x1.evaluate({"y":0})
except UnknownVarError:
    print("Variable without value detected.")
try:
    Divide(Constant(1),Variable("x")).evaluate({"x":0})
except DivByZeroError:
    print("Division by zero detected.")
try:
    Constant("invalid_constant")
except ConstantError:
    print("Invalid constant detected.")