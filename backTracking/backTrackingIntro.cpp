#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>


std::unordered_map<char,std::vector<char>> keyMap;


void recur(std::vector<std::string>& results, std::string crntStr , int crntIdx , const std::string& digits)
{
  const int digitLength = digits.size();
  if(digitLength <= crntIdx)
  {
    if(digitLength != 0)
    {
      results.emplace_back(crntStr);
    }
    return;
  }
  
  const char crntChar = digits[crntIdx];
  const std::vector<char>& alphabets = keyMap[crntChar];
  for(const char alphabet : alphabets)
  {
    recur(results,crntStr+alphabet,crntIdx+1,digits);
  }
}
    
std::vector<std::string> letterCombinations(std::string digits) { 
  keyMap['2'] = {'a','b','c'};
  keyMap['3'] = {'d','e','f'};
  keyMap['4'] = {'g','h','i'};
  keyMap['5'] = {'j','k','l'};
  keyMap['6'] = {'m','n','o'};
  keyMap['7'] = {'p','q','r','s'};
  keyMap['8'] = {'t','u','v'};
  keyMap['9'] = {'w','x','y','z'};
  std::vector<std::string> results;
  std::string crntStr;
  
  recur(results,crntStr,0,digits);
  
  return results;
}


int main()
{
  const auto combinations = letterCombinations("2334");
  for(const auto comb : combinations)
  {
    std::cout << comb << " ";
  }
  std::cout << "\n";
}
