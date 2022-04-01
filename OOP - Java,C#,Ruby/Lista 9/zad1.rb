class Function
	def initialize(blok)
		@wyrazenie = blok
	end

	def value(x)
		return @wyrazenie.call(x)
	end

	def zero(a, b, e)
		wynik=Array.new
		(a..b).step(e) do |x|
			if self.value(x)==0
				wynik << x
			end 
		end
		return wynik
	end

	def field(a,b)
		puts b
		puts a
		pole=0;
		singlestep=0.0+b-a;
		singlestep=singlestep/10000
		puts singlestep
		ending=b-singlestep
		a.step(ending,singlestep) do |x|
			pole= pole + singlestep*(self.value(x)+self.value(x+singlestep))/2
		end	
		return pole
	end

	def derive(x)
		h = 0.0000000001
		return (self.value(x+h)-self.value(x) + 0.0)/h
	end	

end


test1 = Function.new(Proc.new{ |x| x*x*Math.sin(x) })
test2 = Function.new(Proc.new{ |x| x*(x-1)*(x+2) })
puts test1.value(1)
puts test1.derive(0.5)
puts test2.zero(-3,3,0.1)
puts test1.field(0,1)

