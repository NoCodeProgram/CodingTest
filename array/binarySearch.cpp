#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& nums, int target)
{
  int leftIdx = 0;
  int rightIdx = nums.size() - 1;
  
  while( 0 <= (rightIdx - leftIdx) )
  {
    const int centerIdx = (leftIdx + rightIdx) / 2;
    const int centerVal = nums[centerIdx];
    
    if(centerVal == target)
    {
      return centerIdx;
    }
    
    if(target<centerVal)
    {
      rightIdx = centerIdx - 1;         
    }
    else
    {
      leftIdx = centerIdx + 1;
    }
  }  
  return -1;    
}

int main()
{

  std::cout << binarySearch({-1,1,3,5,9,18},9) << std::endl;
}