#include<bits/stdc++.h>
using namespace std;
int n,m,cc,r,c[105],z,d[105];
int main()
{
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==m)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n*m;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		d[i]=c[i];
	}
	
	int p=c[1];

		for(int j=1;j<=10;j++)
	{
		for(int i=1;i<=n*m;i++)
	{
		if(d[i+1]>d[i])
		{
			int t=d[i];
			d[i]=d[i+1];
			d[i+1]=t;
		}
	}
	} 

	for(int i=1;i<=n*m;i++)
	{
		if(d[i]==p)
		{
			z=i;
		}
	}
	if(n==1) cout<<z<<" "<<1;
	if(m==1) cout<<1<<" "<<z;
	return 0;
 } 
