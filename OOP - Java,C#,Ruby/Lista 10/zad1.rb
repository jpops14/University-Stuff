class Collection
	def initialize(arr)
		@tablica = Array.new(arr)
	end

	def getLength()
		return @tablica.length();
	end

	def Swap(i,j)
		@tablica[i], @tablica[j] = @tablica[j], @tablica[i]
	end	

	def get(i)
		return @tablica[i]
	end

	def wypis()
		return @tablica.to_s()
	end	
end


class Sorter
	def initialize()
	end

	def Sort1(kolekcja)                   #BubbleSort
		maxi=kolekcja.getLength()-1
		check=true
		while check==true do
			check=false
			(1..maxi).each do |i|
				if kolekcja.get(i-1)>kolekcja.get(i)
					check=true;
   					kolekcja.Swap(i-1,i)
				end

			end

		end
	end
	
	def Sort2(kolekcja)                  #SelectionSort <--- szybszy
		maxi=kolekcja.getLength()-1
		(0..maxi).each do |i|
        mini=i
        elem=kolekcja.get(i)
        	((i+1)..maxi).each do |j|
        		if kolekcja.get(j)<elem
					mini=j
   					elem=kolekcja.get(j)
   				end	
        	end	
        kolekcja.Swap(i,mini)
		end

	end	
end

ary=[3,4,5,2,1,9,7]
test1=Collection.new(ary);
test2=Collection.new(ary);
puts test1.wypis()
tests=Sorter.new();
tests.Sort1(test1);
puts test1.wypis()
puts test2.wypis()
tests.Sort2(test2);
puts test2.wypis()
