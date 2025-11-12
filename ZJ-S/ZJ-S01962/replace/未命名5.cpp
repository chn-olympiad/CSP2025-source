#include<bits/stdc++.h>
using namespace std;
long long fsc(long long x)
{
	long long a=1;
	while(x--)
		a*=(x+1);
	return a;
}
int main()
{
	cout<<fsc(5);
	return 0;
}
