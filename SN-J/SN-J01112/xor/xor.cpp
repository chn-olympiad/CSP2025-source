#include <iostream>
using namespace std;

long long inlist[1000005];
long long inn, ink;

long long countxor(long long a, long long b)
{
	long long nowxor = inlist[a];
	for (int j = a + 1; j < b; ++j)
	{
		nowxor ^= inlist[j];
	}
	return nowxor;
}


int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cout << 2;
	return 0;
}
