using System;
using System.Collections;


namespace zad2{



	class MojProgram {
		static void Main() {
		
			PrimeCollection pc = new PrimeCollection();
			foreach(int p in pc)
			Console.WriteLine(p);

		}
	}
}