#include <iostream>
#include <vector>

int fib(int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}

	std::vector<int>fibArry {0,1};
	fibArry.reserve(n);
	for( int i=2 ; i<=n ; ++i)
	{
		const int ithNum = fibArry[i-1]+fibArry[i-2];
		fibArry.emplace_back(ithNum);
	}
	return fibArry[n];
}


int main()
{
	std::cout << fib(10) << std::endl;
}