#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N=1e5+10;
const int M=2e4+10;
priority_queue<pair<int,int>,vector<pair<int,int> > > q; 
int maxx,n,T,b[M];
int read()
{
	int sum=0,f=1;
	char xxx=getchar();
	while(xxx<'0'||xxx>'9'){if(xxx=='-')f=-1;xxx=getchar();}
	while(xxx>='0'&&xxx<='9'){sum=sum*10+xxx-'0';xxx=getchar();}
	return sum*f;
} 
struct node{
	int x,y,z;
}a[N+10];
void dfs(int nw,int ans)
{
	if(nw==n+1)
	{
		maxx=max(ans,maxx);
		return;
	}
	int sum=0,pp=0;
	if(b[1]+1<=n/2)
	{
		b[1]++;
		dfs(nw+1,ans+a[nw].x);
		b[1]--;
	}
	if(b[2]+1<=n/2)
	{
		b[2]++;
		dfs(nw+1,ans+a[nw].y);
		b[2]--;
	}
	if(b[3]+1<=n/2)
	{
		b[3]++;
		dfs(nw+1,ans+a[nw].z);
		b[3]--;
	}
}
bool cmp(node aa,node bb){return aa.x>bb.x;}
bool Cmp(node aa,node bb){return aa.x>bb.x||aa.x==bb.x&&aa.y>bb.y;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		maxx=0;
		int f=0,ff=0;
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			a[i].x=read(),a[i].y=read(),a[i].z=read();
			if(a[i].y||a[i].z)f=1;
			if(a[i].z)ff=1;
		}
		if(!f)
		{
			int tot=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)tot+=a[i].x;
			printf("%d\n",tot);
			continue; 
		}
		if(!ff) 
		{
			int tot=0;
			sort(a+1,a+n+1,Cmp);
			for(int i=1;i<=n;i++)
			{
				if(b[1]==n/2&&b[2]==n/2)break;
				if(a[i].x>a[i].y)
				{
					if(b[1]+1<=n/2){b[1]++;tot+=a[i].x;}
					else if(b[2]+1<=n/2)b[2]++,tot+=a[i].y;
				}
				if(a[i].x<a[i].y)
				{
					if(b[2]+1<=n/2){b[2]++;tot+=a[i].y;}
					else if(b[1]+1<=n/2){b[1]++,tot+=a[i].x;}
				}
				if(a[i].x==a[i].y)
				{
					if(b[1]+1<=n/2&&b[2]+1<=n/2)
					{
						(b[1]<b[2]?b[1]++:b[2]++);
						tot+=a[i].x;
					}
					else if(b[1]+1<=n/2)b[1]++,tot+=a[i].x;
					else if(b[2]+1<=n/2)b[2]++,tot+=a[i].y;
				}
			}
			printf("%d\n",tot);
			continue;
		}
		dfs(1,0);
		printf("%d\n",maxx);
	}
 	return 0;
}

