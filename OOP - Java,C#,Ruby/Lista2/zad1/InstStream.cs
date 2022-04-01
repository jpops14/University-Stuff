using System;
using System.Collections.Generic;


namespace zad1{

	class IntStream{

		protected int stream;


	public IntStream()                 ///konstruktor
	{
		this.stream=-1;
	}

	virtual public int next()
	{
		if (this.eos()==false)
		{
			this.stream=stream+1;
			return this.stream;
		}
		else return -1;

	}
	virtual public bool eos()
	{
		if (this.stream == Int32.MaxValue)
		return true;
		else return false;	
	}
	virtual public void reset()
	{
		this.stream=-1;
	}
	

}


class PrimeStream : IntStream{



	public PrimeStream() {
		this.stream=2;
	}
	override public void reset()
	{
		this.stream=2;
	}
	override public int next()
	{

		if (this.eos()==false)
		{
			return prime(this.stream);
		}
		else return -1;
	}

	private int prime(int x){
		
		
		for(int i=x; i <= Int32.MaxValue ;i++)
		{
			bool check=true;
			for(int j=2;j<i;j++)
			{
				if(i%j==0)
				{check=false;
					break;}
				}
				if(check==true)
				{
					this.stream=i+1;	
					return i;
				}

			}
			this.stream=Int32.MaxValue;
			return -1;

		}
		
	}

	class RandomStream : IntStream{
		
		Random x;
		public RandomStream(){
			this.stream=0;
			this.x= new Random();
		}

		override public int next()
		{
			return this.x.Next();
		}

		
	}

	class RandomString{
		RandomStream rand;
		PrimeStream primes;
		public RandomString()
		{
			this.rand=new RandomStream();
			this.primes=new PrimeStream();
		}

		public string next()
		{
			string word="";
			int length=this.primes.next();
			for(int i=1;i<=length;i++)
			{
				char x=(char)((this.rand.next()%94)+33);
				word=word+x;
			}
			return word;
		}

		public bool eos()
		{
			return this.primes.eos();
		}

		public void reset()
		{
			this.primes.reset();
		}

	}

	class MojProgram {
		static void Main() {
			IntStream test1 = new IntStream();
			Console.WriteLine("test Instream");
			Console.WriteLine(test1.next());
			Console.WriteLine(test1.next());
			Console.WriteLine(test1.next());
			test1.reset();
			Console.WriteLine(test1.next());
			Console.WriteLine(test1.next());
			Console.WriteLine(test1.next());
			PrimeStream test2 = new PrimeStream();
			Console.WriteLine("test PrimeStream");
			Console.WriteLine(test2.next());
			Console.WriteLine(test2.next());
			Console.WriteLine(test2.next());
			test2.reset();
			Console.WriteLine(test2.next());
			Console.WriteLine(test2.next());
			Console.WriteLine(test2.next());
			RandomStream test3 = new RandomStream();
			Console.WriteLine("test RandomStream");
			Console.WriteLine(test3.next());
			Console.WriteLine(test3.next());
			Console.WriteLine(test3.next());
			test3.reset();
			Console.WriteLine(test3.next());
			Console.WriteLine(test3.next());
			Console.WriteLine(test3.next());
			Console.WriteLine(test3.next());
			RandomString test4 = new RandomString();
			Console.WriteLine("test RandomStream");
			Console.WriteLine(test4.next());
			Console.WriteLine(test4.next());
			Console.WriteLine(test4.next());
			Console.WriteLine(test4.next());

		}
	}
}