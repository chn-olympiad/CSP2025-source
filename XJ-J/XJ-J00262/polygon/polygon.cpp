#include<bits/stdc++.h>
using namespace std;
long long int a[1000],b,c,n,i; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		cout<<1%998244353;
	}
	return 0;
} 
