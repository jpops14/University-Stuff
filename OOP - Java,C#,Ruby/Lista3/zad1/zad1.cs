using System;

namespace zad1{

	

	class MojProgram {
		static void Main() {
			
         Lista<int> test=new Lista<int>();
         test.push_front(4);
         test.push_back(3);
         test.push_front(5);
         test.push_back(2);
         test.push_front(6);
         test.push_back(1);
         Console.WriteLine(test.is_empty());
         Console.WriteLine(test.pop_front());
         Console.WriteLine(test.pop_front());
         Console.WriteLine(test.pop_front());
         Console.WriteLine(test.pop_back());
         Console.WriteLine(test.pop_back());
         Console.WriteLine(test.pop_back());
         Console.WriteLine(test.is_empty());
		 
		}
	}
}