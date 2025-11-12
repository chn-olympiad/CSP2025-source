#include<bits/stdc++.h>
using namespace std;
long long a[6000];
int n,b[6000];
long long sum;
void f(long long x,long long y,int m,int j)
{
	if(m>=3&&x>y*2)
	{
		sum++;
		sum%=998244353;
	}
	for(int i=j;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			f(x+a[i],max(y,a[i]),m+1,i+1);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	f(0,0,0,1);
	cout<<sum;
	return 0;
}
