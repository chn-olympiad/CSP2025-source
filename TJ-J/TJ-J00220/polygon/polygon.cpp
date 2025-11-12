#include <iostream>
#include <cstdio>
using namespace std;
int n1,n,a[5000],b[100000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<0;
	}
	else
	{
		cout<<n/2;
	}
	return 0;
}
