class Function2D
	def initialize(blok)
		@wyrazenie = blok
	end

	def value(x,y)
		return @wyrazenie.call(x,y)
	end

	def volume(a, b, c, d)
    prec = 0.001
    vol = 0.0
    a.step(c-prec,prec) do |x|
    	b.step(d-prec,prec) do |y|
    		vol+=((self.value(x, y) + self.value(x, y + prec))/2*prec + 
          (self.value(x + prec, y) + self.value(x + prec, y + prec))/2*prec)/2*prec
    	end	
      
    end
    vol
    end

	def contour_line(a, b, c, d, height)
		wynik=Array.new
		singlestep=0.1
		prec=0.01
		a.step(c,singlestep) do |x|
    		b.step(d,singlestep) do |y|
    			temp=0.0+self.value(x,y)-height
    			temp=temp.abs
    			if temp<=prec
    				wynik << [x,y];
    			end	

    		end	
      
    	end
    	return wynik
	end	

end

suma = Function2D.new(Proc.new{|x, y| x + y})
puts suma.value(3, 7)
constfun = Function2D.new(Proc.new{|x, y| 2})
puts "Objetość"
puts constfun.volume(1,2,3,5)
puts "Pary"
suma.contour_line(0, 0, 2, 2, 2).each{|t| puts "x:" + t[0].to_s + " y:" + t[1].to_s}

puts "Koniec testów"