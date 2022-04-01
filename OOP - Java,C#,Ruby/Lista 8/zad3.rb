class Jawna
   def initialize(text)
      @text = text
   end
   def zaszyfruj(key)
     zaszyfrowane=""
     @text.each_char{|c| zaszyfrowane << c=key[c]}
     return Ciphered.new(zaszyfrowane)
   end
   def to_s
      	return @text
   end
end

class Ciphered
   def initialize(name)
      @text = name
   end
   def odszyfruj(key)
     revkey=key.invert
     odszyfrowane=""
     @text.each_char{|c| odszyfrowane << c=revkey[c]}
     return Jawna.new(odszyfrowane)
   end
   def to_s
      	return @text
   end
end



test1 = Jawna.new("ruby")
puts test1.to_s
klucz = { "a" => "b","b" => "r","r" => "y","y" => "u","u" => "a"}
test2=test1.zaszyfruj(klucz)
puts test2.to_s 
test3 = test2.odszyfruj(klucz)
puts test3.to_s 



