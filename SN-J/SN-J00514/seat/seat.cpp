#include<bits/stdc++.h>//n,m行. 数.n 与列. 数. m
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[100],a[10][10],x,y,k=1,l;
	cin>>n>>m;
	cin>>l;
	b[1]=l;
	for(int i=2;i<=n*m;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]<b[i+1])
		{
			int t=b[i];
			b[i]=b[i+1];
			b[i+1]=t;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(b[k]==l)
				{
					x=n;
					y=m;
					break;
				}
				a[n][m]=b[k];
				k++;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
