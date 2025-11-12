#include<bits/stdc++.h>
using namespace std;
long long int f,n,m,i,b[5000005],x;
char a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	f=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]=='0')
		{
			f=1; 
		}
	}
	for(i=1;i<=n;i++)
	{
		cin>>x;
		b[x]++;
	}
	if(m==n&&f==0)
	{
		for(i=1;i<=500;i++)
		if(b[i]>=2)
		{
			cout<<0;
			return 0;
		}
		if(b[0]>=2)
		{
			cout<<0;
			return 0;
		}
		cout<<1;
	}
	return 0;
}
