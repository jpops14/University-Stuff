using System;
using System.Collections;


namespace zad2{

public class PrimeCollection : IEnumerable 
{
	

	///interfejs enumerable

	IEnumerator IEnumerable.GetEnumerator()
    {

       return (IEnumerator) GetEnumerator();
    }

    public PrimeEnum GetEnumerator()
    {
        return new PrimeEnum();
    }

}

public class PrimeEnum : IEnumerator{

			int curprime;
			public PrimeEnum()
			{
			this.curprime=1;
			}

			public bool MoveNext() {

    			for(int i=this.curprime+1;i<=int.MaxValue;i++)
				{
		 			bool check=true;
          			for(int j=2;j<i;j++)
              		{
              				if(i%j==0)
              				{
              				check=false;
              				break;
              				}
              		}
          	    	if (check==true)
                	{
          	    		this.curprime=i;
          				break;
          			}
				}


    			return this.curprime<int.MaxValue;
			}

			public object Current{
				get{
			 	return this.curprime;
			 		}
			 }


			public void Reset(){
				//Console.WriteLine("reset");
			 	this.curprime=1;
			 }

		}
	

}