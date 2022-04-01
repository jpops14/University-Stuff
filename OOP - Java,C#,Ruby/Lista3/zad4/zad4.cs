using System;


namespace zad4{

	

	class MojProgram {
		static void Main() {
			
           Wektor test1=new Wektor(3,3,3,3);
            Console.WriteLine("Wektor a:");
            test1.wypisz();
           Wektor test2=new Wektor(2,2,2,2);
            Console.WriteLine("Wektor b:");
            test2.wypisz();
           Wektor test3=test1+test2;
           Console.WriteLine("Wektor a+b:");
           test3.wypisz();
           test3=test1*test2;
           Console.WriteLine("Wektor a*b:");
           test3.wypisz();
           test3=test1*3;
           Console.WriteLine("Wektor a*3:");
           test3.wypisz();
           Console.WriteLine("norma(b):");
           Console.WriteLine(test2.norma());



		}
	}
}