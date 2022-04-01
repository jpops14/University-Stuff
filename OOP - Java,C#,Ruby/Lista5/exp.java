import java.io.*;

public class exp{
public static void main(String[] args){

	 Expression expr=new Add(new Mult(new Const(3),new Var("x")),new Var ("y"));
   	 String[] variables=new String[2];
   	 int[] varvalues=new int[2];
   	 variables[0]="x";
   	 variables[1]="y";
   	 varvalues[0]=2;
   	 varvalues[1]=5;
   	  System.out.println("Wyrażenie arytmetyczne:");
   	  System.out.println(expr.toString());
   	  System.out.println("Wartość wyrażenia 1 dla x=2 i y=5:");
   	  System.out.println(expr.evaluate(variables,varvalues));
   	  Expression expr2=new Add(new Mult(new Var("x"),new Var("x")),new Mult(new Const(4),new Mult(new Var("x"),new Mult(new Var("x"),new Var("x")))));
   	  System.out.println("Funkcja f(x):");
   	  System.out.println(expr2.toString());
   	  Expression expr3=expr2.derivate();
   	   System.out.println("Pochodna funkcji f(x):");
   	  System.out.println(expr3.toString());

}


}
abstract class Expression{
	public abstract int evaluate();
	public abstract int evaluate(String[]variables , int[]varvalues);
	public abstract String toString();
	public abstract Expression derivate();

}

public class Add extends Expression{
	private Expression left;
	Expression right;
	Add(Expression x,Expression y)
	{
		this.left=x;
		this.right=y;
	}

	public int evaluate()
	{
		return left.evaluate()+right.evaluate();
	}
	public int evaluate(String[]variables , int[]varvalues)
	{
		return (left.evaluate(variables,varvalues)+right.evaluate(variables,varvalues));
	}
	public String toString()
	{
		
		return "("+this.left.toString()+"+"+this.right.toString()+")";
	}
	public Expression derivate()
	{
		return new Add(this.left.derivate(),this.right.derivate());
	}

}

public class Mult extends Expression{
	private Expression left;
	private Expression right;

	Mult(Expression x,Expression y)
	{
		this.left=x;
		this.right=y;
	}

	public int evaluate()
	{
		return left.evaluate()*right.evaluate();
	}
	public int evaluate(String[]variables , int[]varvalues)
	{
		return (left.evaluate(variables,varvalues)*right.evaluate(variables,varvalues));
	}
	public String toString()
	{
		
		return "("+this.left.toString()+"*"+this.right.toString()+")";
	}
	public Expression derivate()
	{
		return new Add(new Mult(this.left,this.right.derivate()),new Mult(this.left.derivate(),this.right));
	}


}

public class Const extends Expression{
	private int constant;

	Const(int x){
		this.constant=x;
	}

	public int evaluate()
	{
		return constant;
	}
	public int evaluate(String[]variables , int[]varvalues)
	{
		return constant;
	}
	public String toString()
	{
		Integer temp=constant;
		return temp.toString();
	}
	public Expression derivate()
	{
		return new Const(0);
	}


}

public class Var extends Expression{
	String variable;

	Var(String x){
		this.variable=x;
	}

	public int evaluate(){
		System.out.println("error - napotkano zmienną podczas ewaluacji bez zmiennych");	
		return 0;
	}
	public int evaluate(String[]variables , int[]varvalues)
	{	
		for(int i=0;i<varvalues.length;i++)
			if(variable==variables[i]){
				return varvalues[i];
			}
		System.out.println("error - nie rozpoznano zmiennej");	
		return 0;	
	}
	public String toString()
	{
		
		return  this.variable;
	}
	public Expression derivate()
	{
		return new Const(1);
	}


}



