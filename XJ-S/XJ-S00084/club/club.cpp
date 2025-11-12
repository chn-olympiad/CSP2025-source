#include<bits/stdc++.h>
using namespace std;
long long n,maxx=0;
struct node
{
	long long g1,g2,g3;
}a[1000005];
bool cmp(node x,node y)
{
	if(x.g1<y.g1)
		return x.g1>y.g1;
}
void bfs(long long i,long long j,long long sum,long long b1,long long b2,long long b3)
{
	if(j==1&&b1<=n/2)
	{
		sum=sum+a[i].g1;
	}
	else if(j==2&&b2<=n/2)
	{
		sum=sum+a[i].g2;
	}
	else if(j==3&&b3<=n/2)
	{
		sum=sum+a[i].g3;
	}
	if(sum>maxx)
	{
		maxx=sum;
	}
	if(i==n)
	{
		return;
	}
	if(b1+1<=n/2)
		bfs(i+1,1,sum,b1+1,b2,b3);
	if(b2+1<=n/2)
		bfs(i+1,2,sum,b1,b2+1,b3);
	if(b3+1<=n/2)
		bfs(i+1,3,sum,b1,b2,b3+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		maxx=0;
		long long x=1,y=1,sum=0;
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i].g1>>a[i].g2>>a[i].g3;
			if(a[i].g2!=0)
			{
				x=0;
			}
			if(a[i].g3!=0)
			{
				y=0;
			}
		}
		if(y==1)
		{
			if(x==1)
			{
				sort(a+1,a+n+1,cmp);
				for(long long i=1;i<=n/2;i++)
				{
					sum=sum+a[i].g1;
				}
				cout<<sum;
				return 0;
			}	
		}
		bfs(1,1,0,1,0,0);
		bfs(1,2,0,0,1,0);
		bfs(1,3,0,0,0,1);
		cout<<maxx<<endl;
	}
	return 0;
} 
