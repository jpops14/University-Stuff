import java.io.*;
import java.util.*;

public class MergeTableTest{
public static void main(String[] args){
	Float [] tablica={2.0f,5.0f,3.0f,1.0f,9.0f,3.0f,7.0f,5.0f};
	MergeTable<Float> example=new MergeTable<Float>(tablica);
	Thread watek=new Thread(example);
	watek.start();
	try{
		watek.join();
		}

		catch(Exception placeholder)
		{

		}	
	for(int i=0;i<example.a.length;i++)
		System.out.println(tablica[i]);	
	
}
}




class MergeTable<T extends Comparable<T> > implements Runnable{
	T[] a;

	MergeTable(T [] tab){
		this.a=tab;
	}

	public synchronized void Merge()
	{
		if(a.length<=1)
		return;

		int mid=a.length/2;
		T[] right = Arrays.copyOfRange(a, mid, a.length);
		T[] left = Arrays.copyOfRange(a, 0, mid);
		MergeTable<T> half1=new MergeTable<T>(left);
		MergeTable<T> half2=new MergeTable<T>(right);
		Thread t1=new Thread(half1);
		Thread t2=new Thread(half2);
		t1.start();
		t2.start();
		try{
			t1.join();
			t2.join();
			}

		catch(Exception placeholder)
		{

		}	

		int i=0;
		int j=0;
		int glowny=0;

		while(i<half1.a.length&&j<half2.a.length)
		{
			if(half1.a[i].compareTo(half2.a[j])<0)
				a[glowny++]=half1.a[i++];
			else a[glowny++]=half2.a[j++];
		}
		if(i>=half1.a.length)
		{
			while(j<half2.a.length)
				a[glowny++]=half2.a[j++];
		}
		else if(j>=half2.a.length)
		{
			while(i<half1.a.length)
				a[glowny++]=half1.a[i++];
		}




	}




	public void run(){
		this.Merge();
	}

}


