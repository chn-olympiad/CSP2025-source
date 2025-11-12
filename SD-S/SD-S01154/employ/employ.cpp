#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define ll long long
int m,n,a[505],c[505],q=0;
ll p=1,p1=1;
string s;
int main()
{
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		a[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0) q++;//弃权 
	}
	if(n-q<m)
	{
		cout<<0<<endl;
		return 0;
	}
	sort(c+1,c+1+n);
	int t=n-m;//可以放弃的人数 
	t-=q;
//	for(int i=n-q;i>1;i--)
//	{
//		p*=i;
//		p%=998244353;
//	}
//	for(int i=q;i>1;i--)
//	{
//		p1*=i;
//		p1%=998244353;
//	}
//	p=p1*p%998244353;
	//不舍 
	ll qjie=1;
	for(int i=q;i>1;i--)
	{
		qjie*=i;
	}
//	bool c=1;
//	for(int i=1;i<=t&&c=1;i++)
//	{
//		ll x,y;
//		if(q<c[i])
//		{
//			continue;
//		}
//		for(int i=n-q+c[i];i>1;i--)
//		{
//			x*=i%998244353;
//			x%=998244353;
//		}
//		for(int i=q-c[i];i>1;i--)
//		{
//			y*=i%998244353;
//			y%=998244353;
//		}
//		for(int i=c[i];i>1;i--)
//		{
//			x*=i%998244353;
//			x%=998244353;
//		}
//		for(int i=q-c[i];i>1;i--)
//		{
//			x*=i%998244353;
//			x%=998244353;
//		}
//		p+=(x*y)%998244252;
//		c=0;
//	}
	if(c[t]>q)
	{
		for(int i=n-q;i>1;i--)
		{
			p*=i;
			p%=998244353;
		}
		for(int i=q;i>1;i--)
		{
			p1*=i;
			p1%=998244353;
		}
		p=p1*p%998244353;
		cout<<p<<endl;
		return 0;
	}
	ll x,y,z;
	for(int i=n-q+c[t];i>1;i--)
	{
		x*=i%998244353;
		x%=998244353;
	}
	for(int i=q-c[t];i>1;i--)
	{
		y*=i%998244353;
		y%=998244353;
	}
	for(int i=c[t];i>1;i--)
	{
		z*=i%998244353;
	}
	for(int i=q-c[t];i>1;i--)
	{
		z*=i%998244353;
	}
	p+=(x*y*(qjie/z))%998244252;
	cout<<p<<endl;
	return 0;
}
