#include<bits/stdc++.h>
using namespace std;
int a[505];
int b[505];
long long mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int oo=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			oo++;
		} 
	}
	if(oo==n)
	{
		long long qweqwe=1,qweqweqwe;
		for(int i=1;i<=n;i++)
		{
			qweqwe*=i;
			qweqwe%=mod;
		}
		cout<<qweqwe;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			b[i]=b[i-1]+1;	
		}
		else
		{
			b[i]=b[i-1];
		}
	}
	return 0;
}
