using System;
using System.Collections.Generic;


namespace zad4{

class ListaLeniwa{

	protected List<int> mylist;
	Random x;

	public ListaLeniwa()                 ///konstruktor
	{
		this.mylist = new List<int>();
		this.x = new Random();
	}

	virtual protected void extend(int a, int b)
	{
		for(int i=a; i<b ; i++)   //dodawanie brakujących elementów
        	{
        		this.mylist.Add(x.Next());
        		///Console.WriteLine("test");
        	}
       
	}

	public int element(int x)
	{
		if(x < 0)
		return -1;

        if(x > this.mylist.Count)
        {
        	this.extend(this.mylist.Count,x);
        	return this.mylist[x-1];
        }
        else{                            //odczytanie elementu
           return this.mylist[x-1];
        }
	}

	public int size(){
 		return this.mylist.Count;
}
}

class Pierwsze : ListaLeniwa{

	public Pierwsze() {}

	private int prime(int x){
		    if(x == 0)
		    return 2;
		    else
            for(int i=this.mylist[x-1]+1; i < Int32.MaxValue ;i++)
            {
            	bool check=true;
            	for(int j=2;j<i;j++)
            	{
            		if(i%j==0)
            		{check=false;
            	      break;}
            	}
            	if(check==true)
            	return i;

            }
            return -1;

	}

	override protected void extend(int a,int b){

      for(int i=a; i<b ; i++)   //dodawanie brakujących elementów
        	{
        		this.mylist.Add(this.prime(this.mylist.Count));
        		///Console.WriteLine("test");
        	}
            

	}
}


class MojProgram {
static void Main() {

Console.WriteLine("test LeniwaLista");

ListaLeniwa test = new ListaLeniwa();
Console.WriteLine(test.element(5));
Console.WriteLine(test.size());
Console.WriteLine(test.element(5));
Console.WriteLine(test.size());
Console.WriteLine(test.element(23));
Console.WriteLine(test.size());
Console.WriteLine(test.element(13));
Console.WriteLine(test.size());

Console.WriteLine("test Pierwsze");

Pierwsze test2 = new Pierwsze();

Console.WriteLine(test2.element(5));
Console.WriteLine(test2.element(3));
Console.WriteLine(test2.element(1));
Console.WriteLine(test2.size());

}
}
}