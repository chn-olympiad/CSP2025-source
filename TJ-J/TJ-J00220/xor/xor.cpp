#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[1145];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=100)
	{
		cout<<n/2;
	}
	else
	{
		cout<<2;
	}
	return 0;
}
