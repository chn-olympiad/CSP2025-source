#include<bits/stdc++.h>
using namespace std;
long long si=1,z,ma,n,a[5005],s[5005],an,x[5005],c;
bool f=1,v[5005];
void dt (int i)
{
	if(!i)
	{
		ma=z=0;
		for(int j=1;j<=i;j++)
		{
			ma=max(x[j],ma);
			z+=x[j];
		}
		if(z>ma*2)an++;
	}
	for(int j=1;j<=n;j++)
	{
		if(v[j]==0)
		{
			v[j]=1;
			x[++si]=a[j];
			dt(i-1);
			si--;
			v[j]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]>=3)
		{
			an+=s[i]-2;
			s[i]=2;
		}
		
	}
	if(n<=3)
	{
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])
			cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)f=0;
	}
	if(f)
	{
		cout<<an;
		return 0;
	}
	sort(a+1,a+n);
	for(int i=1;i<=n;i++)
	{
		c=i;
		dt(i);
	}
	cout<<an;
	return 0;
} 
