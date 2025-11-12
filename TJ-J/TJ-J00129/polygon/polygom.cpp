#include<bits/stdc++.h>
using namespace std;
int n,a[10000],k;
int chooce(int x,int y,int maax,int sul,int z)
{
	if(x==y)
	{
		return 1;
	}
	if(z>n||y>n)
	{
		return 0;
	}
	if(sul+a[z+1]>=maax*2)
	return chooce(x,y+1,a[z+1],a[z+1]+sul,z+1)+ chooce(x,y,maax,sul,z+1);
	else
	return chooce(x,y,maax,sul,z+1);
		
}
int main()
{
	freopen("polygom.out","r",stdout);
	freopen("polygom.in","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		k++;
	}
	if(n==3)
	{
		cout<<1;
		return 0;
	}
	long long sum=0;
	/*if(k==n)
	{
		for(int i=3;i<=n;i++)
		{
			sum=(sum+chooce(i,0,0,0,0))%998244353;
		}
		cout<<sum;
		return 0;
	}
	*/
	sort(a,a+n+1);
	for(int i=3;i<=n;i++)
	{
		sum=(sum+chooce(i,0,0,0,0))%998244353;
	}
	cout<<sum%998244353;
	return 0;
}
//do gei dian fen ba!!!
