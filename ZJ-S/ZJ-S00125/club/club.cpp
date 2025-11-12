#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct st
{
	int x,y,z;
}a[100005];
priority_queue<int> q;
int vis[1000001];
int f[201][101][101];
bool cmp(int x,int y)
{
	return x>y;
}
int num(int i,int j,int k)
{
	return max(max(0,(k==0?0:(f[i-1][j][k-1]+a[i].z))),max((j==0?0:(f[i-1][j-1][k]+a[i].y)),(f[i-1][j][k]+a[i].x)));
}
bool check1()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i].y) return 0;
		if(a[i].z) return 0;
	}
	return 1;
}
bool check2()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i].z) return 0;
	}
	return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	int d=0;
	cin>>d;
	if(d>=100000)
	{
		while(t--)
		{
			if(d==0)
			scanf("%d",&n);
			else
			{
				n=d;
				d=0;
			}
			memset(f,0,sizeof f);
			for(int i=1;i<=n;i++)
			{
				scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			}
			if(check1())
			{
				for(int i=1;i<=n;i++)
				{
					q.push(a[i].x);
				}
				int sum=0;
				for(int i=1;i<=n/2;i++)
				{
					sum+=q.top();
					q.pop();
				}
				cout<<sum<<"\n"; 
			}
		}
		return 0;
	}
	while(t--)
	{
		if(d==0)
			scanf("%d",&n);
			else
			{
				n=d;
				d=0;
			}
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		f[0][0][0]=0;
		f[0][1][0]=-100000001;
		f[0][0][1]=-100000001;
	//	f[0][1][1]=-100000001;
		for(int i=1,count=1;count<=n;i^=1,count++)
		{
			for(int j=0;j<=min(count,n/2);j++)
			{
				for(int k=0;k<=min(count-j,n/2);k++)
				{
					if(count-j-k<=n/2)
					{
						f[count][j][k]=num(count,j,k);
					}
				}
			}
		}
	
//			for(int j=0;j<=n/2;j++)
//			{
//				for(int k=0;k<=n/2;k++)
//				{
//					cout<<0<<" "<<j<<" "<<k<<" "<<f[0][j][k]<<"\n";
//				}
//			}
	
		int ans=0;
		for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
		if(n-i-j<=n/2)
			ans=max((int)ans,max((int)f[n][i][j],(int)f[n][i][j]));
		cout<<ans<<'\n';
}
	fclose(stdin);
	fclose(stdout);
	
return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/ 
