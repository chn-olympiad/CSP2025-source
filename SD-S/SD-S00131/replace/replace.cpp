#include<bits/stdc++.h>
using namespace std;
int n,q,s,m;
char a[110][110],b[110][110];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=q;j++)
		{
			cin>>a[i][j]>>b[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]+=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			s=a[i][j]+=1;
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			m=s-m;
		}
	}
	cout<<s<<endl;
	cout<<m;
	return 0;
}
