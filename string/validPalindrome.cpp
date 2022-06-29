#include <iostream>
#include <string>


bool isPalindrome(const std::string & s)
{
  int leftIdx = 0;
  int rightIdx = s.size()-1;
  
  while(leftIdx <= rightIdx)
  {
    char leftChar = s[leftIdx];
    if(!std::isalnum(leftChar))
    {
      leftIdx++;
      continue;
    }
    char rightChar = s[rightIdx];
    if(!std::isalnum(rightChar))
    {
      rightIdx--;
      continue;
    }
    
    leftChar = std::tolower(leftChar);
    rightChar = std::tolower(rightChar);
    if(leftChar!=rightChar)
    {
      return false;
    }
    
    leftIdx ++;
    rightIdx--;
  }
  return true;
    
}

int main()
{
  const std::string s{"A man, a plan, a canal: Panama"};
  std::cout << isPalindrome(s) << std::endl;  
}