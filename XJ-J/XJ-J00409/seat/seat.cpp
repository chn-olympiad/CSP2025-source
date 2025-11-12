#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b;
}b[10000005];
bool cmp(node a,node b)
{
	return a.a>b.a;
}
long long int a[15][15],n,m,i,j,k,p;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>b[i].a;
	}
	p=b[1].a;
	sort(b+1,b+1+n*m,cmp);
	k=0;
	for(i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(j=1;j<=m;j++)
			{
				a[i][j]=b[++k].a;
				if(p==a[i][j])
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else
		{
			for(j=m;j>=1;j--)
			{
				a[i][j]=b[++k].a;
				if(p==b[k].a)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 
