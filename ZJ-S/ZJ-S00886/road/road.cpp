#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+10;
struct node{
	int x,y,z,xx;
}a[N];
int n,m,k,b[10][N],x,f[N],ans;
int dis[1005][1005];
unordered_map<int,bool>mp;
unordered_map<int,int>mp1;
bool cmp(node o,node p)
{
	return o.z<p.z;
}
int zz(int x)
{
	if(f[x]==x)return x;
	else return f[x]=zz(f[x]);
}
int kr()
{
	for(int i=1;i<=n;i++)f[i]=i;
	sort(a+1,a+m+1,cmp);
	int tot=0,cnt=0;bool fl=0;
	for(int i=1;i<=m;i++)
	{
		int xx=zz(a[i].x);bool fl1=0;
		int yy=zz(a[i].y);
		if(xx==yy)continue;
		f[xx]=yy;
		if(a[i].xx!=0)
		{
			mp[a[i].xx]=1;
			fl=1;
		}
		cnt++;
			for(auto y:mp)
			{
				if(y.second==1)
				{
					if(b[mp1[y.first]][xx]+b[mp1[y.first]][yy]<=a[i].z)
					{
						tot+=b[mp1[y.first]][xx]+b[mp1[y.first]][yy];
						fl1=1;
					}
				}
			}			
		if(mp[a[i].xx]==1)
		{
			tot-=a[i].xx;
		}
		if(fl1==0)tot+=a[i].z;
		if(cnt==n-1)return tot;
	}
	if(cnt==n-1)return tot;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].xx=0;
		dis[a[i].x][a[i].y]=dis[a[i].y][a[i].x]=a[i].z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>x;mp1[x]=i;
		bool fl=0;
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
			if(b[i][j]!=0)fl=1;
		}
		if(fl==0&&x==0)
		{
			cout<<0<<"\n";
			return 0;
		}
		for(int j=1;j<=n;j++)
		{
			for(int l=j+1;l<=n;l++)
			{
				if(dis[j][l]==0||dis[j][l]>b[i][j]+b[i][l]+x)
				{
					m++;
					a[m].x=j,a[m].y=l,a[m].z=b[i][j]+b[i][l]+x,a[m].xx=x;
					dis[j][l]=b[i][j]+b[i][l]+x;					
				}
			}
		}
	}
	ans=kr();
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
