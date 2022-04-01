#include <iostream>
#include<string>
#include<vector>

using namespace std;

const vector<pair<int, string>> rzym =
{
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100,"C"}, {90,"XC"},{50, "L"}, {40, "XL"}, {10,"X"}, {9, "IX"}, {5, "V"}, {4, "IV"},{1, "I"}
};

int convert(char * x)
{
    string word=x;
   /* int wordlength=size(word);
    for(int i=0; i<wordlength; i++)
    {

        char symbol=word[i];
        if(symbol<'0' || symbol>'9');
        {
            clog << "can't convert to number - forbidden symbols detected\n";
            return 0;
        }
    }
    */
    int number;
    try {
        number=stoi(word);
    }
    catch (const std::invalid_argument& ia){
        std::clog << "invalid argument - not a number\n";
        return 0;
    }
    catch (const std::out_of_range& oor){
       std::clog << "invalid argument - number out of range \n";
        return 0;
    }


    if (number<1 || number>3999)
    {
        std::clog << "invalid number\n";
        return 0;
    }
    else return number;
}

std::string bin2rzym (int x)
{
    string roman="";
    for(int i=0; i<13; i++)
    {
        while(x>=rzym[i].first)
        {
            roman+=rzym[i].second;
            x-=rzym[i].first;
        }

    }
    return roman;
}




int main(int argc, char *argv[])
{
   for (int i=1;i<argc;i++)
   {
     int x=convert(argv[i]);
     if(x>=1)
     std:cout << bin2rzym(x) << "\n";
   }
}


