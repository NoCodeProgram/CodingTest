#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums)
{
  std::size_t fromIdx = 0;
  std::size_t toIdx = 0;
  
  const std::size_t vecSize = nums.size();
  
  while( fromIdx < vecSize)
  {
    if( nums[fromIdx] == 0)
    {
      fromIdx++;
    }
    else
    {
      nums[toIdx] = nums[fromIdx];
      fromIdx++;
      toIdx++;
    }
  }
  
  while ( toIdx < vecSize)
  {
    nums[toIdx] = 0;
    toIdx++;
  }
        
}

int main()
{
  std::vector<int> nums{0,1,0,3,12};
  moveZeroes(nums);

  for(auto num:nums)
  {
    std::cout << num << " ";
  }
}