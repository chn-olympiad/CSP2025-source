#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Mod=998244353;
ll n,a[5005],d[11];
ll j[5005];
ll ksm(ll a,ll b)
{
	if(b==1)
		return a;
	if(b%2==0)		
		return ksm((a*a)%Mod,b/2)%Mod;
	else
		return (ksm((a*a)%Mod,(b-1)/2)*a)%Mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		d[a[i]]++;
	}
	if(n<=3)
	{
		int x=a[1],y=a[2],z=a[3];
		if(x+y>z&&z+y>x&&x+z>y)
			cout<<1;
		else
			cout<<0;
	}
	else if(d[1]==n)
	{
		cout<<ksm(2,n)-1-n-n*(n-1)/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}