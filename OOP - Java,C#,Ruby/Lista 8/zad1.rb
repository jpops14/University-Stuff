class Integer
 def czynniki
 	tab=Array.new
 	1.upto(9) do |x|
		if self % x == 0
			tab.push(x)
			end
		end
	return tab
 end
 def doskonala
 	tab=self.czynniki
 	sum = 0
	tab.each { |a| sum+=a }
	sum-= self
	if sum == self
	   return true
	else
	   return false
	end      	
 	
 end
 
 def slownie
 	assoc = { "0" => "zero" , "1" => "jeden", "2" => "dwa","3" => "trzy","4" => "cztery" ,
 	"5" => "piec", "6" => "szesc", "7" => "siedem", "8" => "osiem", "9" => "dziewiec" }
 	zapis=self.to_s
 	slowny=""
 	zapis.each_char{|c| slowny << c=assoc[c] << " "}
 	return slowny
 end
 
 def ack(m)
 	if self==0
 		return m+1
 	elsif m==0
 		return (self-1).ack(1)	
 	else
 		return (self-1).ack(self.ack(m-1))
 	end
 
 end
end

puts 2.ack(1)
puts 6.doskonala
puts 5.doskonala
print 6.czynniki
print "\n"
puts 123.slownie


