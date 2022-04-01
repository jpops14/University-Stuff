using System;


namespace zad4{


public class Wektor{

      private int size;
      private float [] tab;

      public Wektor(params float [] num)
      {
        this.tab=num;
        size=tab.Length;
      }
/*
      public Wektor(int newsize, float [newsize] tablica)
      {
      	this.tab=tablica;
        size=tab.Length;
      }
*/

      public static Wektor operator + (Wektor a,Wektor b)
      {
      	int maxsize=Math.Max(a.size,b.size);
      	int minsize=Math.Min(a.size,b.size);
 
      	float[] array = new float[maxsize];	
      	for(int i=0;i<minsize;i++)
      	   array[i]=a.tab[i]+b.tab[i];
      	   
      	for(int i=minsize;i<maxsize;i++)
      	   if(a.size>b.size)
      	   array[i]=a.tab[i];
      	   else array[i]=b.tab[i];   

      	return new Wektor(array); 
      }


      public static Wektor operator * (Wektor a,Wektor b)
      {
 
      	int maxsize=Math.Max(a.size,b.size);
      	int minsize=Math.Min(a.size,b.size);
 
      	float[] array = new float[maxsize];		
      	for(int i=0;i<a.size;i++)
      	   array[i]=a.tab[i]*b.tab[i];

      	for(int i=minsize;i<maxsize;i++)
      	   if(a.size>b.size)
      	   array[i]=a.tab[i];
      	   else array[i]=b.tab[i];   

      	return new Wektor(array);
      }


      public static Wektor operator *(Wektor a,float b)
      {
      	float[] array = new float[a.size];	
      	for(int i=0;i<a.size;i++)
      	   array[i]=a.tab[i]*b;
      	return new Wektor(array);
      }

      public static Wektor operator *(float b,Wektor a)
      {
        float[] array = new float[a.size];	
      	for(int i=0;i<a.size;i++)
      	   array[i]=a.tab[i]*b;
      	return new Wektor(array);
      }

      public float norma(){
      	float length=0;
      	Wektor kwadrat=new Wektor(this.tab);
      	kwadrat=kwadrat*kwadrat;
      	for(int i=0;i<this.size;i++)
      	{
      		length+=kwadrat.tab[i];
      	}
      	return MathF.Sqrt(length);
      }
     
      public void wypisz()
      {
      	Array.ForEach(this.tab, Console.WriteLine);
      }


	}

}