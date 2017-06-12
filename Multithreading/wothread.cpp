#include <iostream>


long long result = 0, n;

int main()
{
	n = 10000000;
	//std::cin >> n;
	for(long long i = 1; i <= n; i++)
		result += i;
	std::cout<<result;
}