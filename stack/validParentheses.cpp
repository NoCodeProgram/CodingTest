#include <string>
#include <iostream>
#include <vector>

bool validParentheses(const std::string & s) {
  const std::size_t strSize = s.size();
  std::vector<char> charStack;
  charStack.reserve(strSize);
  
  for(const char c:s)
  {
    if(c=='(' || c=='[' || c=='{')
    {
      charStack.emplace_back(c);
      continue;
    }
    
    if(charStack.size()==0)
    {
      return false;
    }
    
    const char lastChar = charStack.back();
    if(lastChar=='(' && c==')')
    {
      charStack.pop_back();
      continue;
    }
    
    if(lastChar=='[' && c==']')
    {
      charStack.pop_back();
      continue;
    }
    
    if(lastChar=='{' && c=='}')
    {
      charStack.pop_back();
      continue;
    }        
    return false;        
  }
  
  if(charStack.size()==0)
  {
    return true;
  }
  return false;
    
}


int main(int argc, char const *argv[])
{
  std::cout << validParentheses("()[]{}") << std::endl;
  std::cout << validParentheses("({)(})") << std::endl;
}