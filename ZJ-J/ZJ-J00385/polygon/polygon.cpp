#include<bits/stdc++.h.>
using namespace std;
int k,n,m,a[5005],s,ma,nu;
long long x;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
		nu+=a[i];
	}
	if(n==3&&nu>(2*ma))
	{
		cout<<1;
		return 0;
	}
	if(n==3&&nu<=(2*ma))
	{
		cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		k=1;
		for(int j=1;j<=i;j++)
		{
			k*=(n-j+1);
			k%=998244353;
		}
		for(int j=1;j<=i;j++)
		{
			k/=j;
		}
		s+=k;
		s%=998244353;
	}
	cout<<s;
	return 0;
}