#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int b[5005];
int c[5005];
int d[5005][5005];
int tot;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
		c[i]=a[i]*2;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<" ";
		
	}cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<c[i]<<" ";
	}cout<<endl;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j]=d[i-1][j-1]+b[i];
			if(d[i][j]>c[j]) tot++;
			d[i][j]=d[i][j-1]+b[i];
			if(d[i][j]>c[j]) tot++;
			d[i][j]=d[i-1][j]+b[i];
			if(d[i][j]>c[j]) tot++;
			tot=tot%998244353;
			
		}
	}
	cout<<tot/n%998244353;
	
	
}
