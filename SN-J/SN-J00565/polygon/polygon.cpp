#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int mud=998244353;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	int fa=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) fa=0;
	}
	if(n==3)
	{
		sort(a,a+3,cmp);
		if(a[0]+a[1]+a[2]>a[0]*2) cout<<1;
		else cout<<0;
		return 0;
	}
	if(fa)
	{
		long long r=0;
		for(int i=3;i<=n;i++)
		{
			long long b=1,c=1;
			for(int j=1;j<=i;j++)
			{
				b=b*j;
				b=b%mud;
				c*=(n+1-j);
				c%=mud;
			}
			r+=(c/b);
			r%=mud;
		}
		cout<<r;
		return 0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
