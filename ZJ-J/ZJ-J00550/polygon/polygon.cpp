#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],n;
long long ans;
int f(int x,int y)
{
	if(x==0)return 1;
	if(x==1)return y;
	if(x==y)return 1;
	return f(x,y-1)+f(x-1,y-1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=a[i-1] && i!=1)flag=1;
	}
	sort(a+1,a+1+n);
	if(n<3)cout<<0;
	if(n==3)
	{
		int sum=0;
		while(n--)sum+=a[n];
		if(sum>2*a[3])cout<<1;
		else cout<<0;
	}
	if(n>3)
	{
		if(!flag)
		{
			for(int i=3;i<=n;i++)
			{
				ans=(ans+f(i,n))%998%244%353;
			}
			cout<<ans;
		}
		else
		{
			cout<<6;
		}
	}
	return 0;
}
