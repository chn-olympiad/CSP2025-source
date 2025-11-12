#include<bits/stdc++.h>
using namespace std;
int n,a[500010];
long long ans=0,f[500010];
bool cmp(int a,int b)
{
	return a>b;
}
bool check(int l,int r)
{
	int m=-1;
	for(int i=l;i<=r;i++)
		m=max(m,a[i]);
	if(f[r]-f[l-1]>2*m)	return 1;
	return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=f[i-1]+a[i];
	}
	sort(1+a,1+a+n,cmp);
	int l=1,r=3;
	while(l<=n-2)
	{
		if(check(l,r)==1)
			ans++;
		r++;
		if(r>n)
		{
			l++;
			r=l+2;
		}
		ans=ans%998244353;
	}
	cout<<ans%998244353;
	return 0;
}
