#include<bits/stdc++.h>
using namespace std;
int n,m,p=1;
int s[10001],c[10001];
int main()
{
	freopen("employ.in","r",stdin);	
	freopen("employ.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int j=1;j<=p;j++)
	{
		cin>>c[j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			s[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[j]++;
			p=s[i]-c[j];
		}
	}
	cout<<p+1;
	return 0;
}
