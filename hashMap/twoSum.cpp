#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> hash;
    std::vector<int> resultVector{0,0};
    for(int i = 0 ; i< nums.size() ; i ++)
    {
        int numberToFind = target - nums[i];
        const auto itr = hash.find(numberToFind);
        if(itr != hash.end())
        {
            resultVector[0] = itr->second;
            resultVector[1] = i;
            break;
        }
        hash.insert({nums[i],i});
    }
    return resultVector;
}


int main(int argc, char const *argv[])
{
    const std::vector<int> retIdxs = twoSum({2,7,11,15},9);
    for(const int num : retIdxs)
    {
        std::cout <<  num << " ";
    }
    return 0;
}