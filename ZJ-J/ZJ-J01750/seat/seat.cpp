#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int n,m,t,k,d[N][N];
struct seat{
	int z;
	int id;
}a[1000];
bool cmp(seat _1,seat _2)
{
	return _1.z>_2.z;
}
bool vis[100][100];
void dfs(int x,int y,int now)
{
	if(y>m) return;
	vis[x][y]=true;
	d[x][y]=now;
	if(!vis[x+1][y]&&x+1<=n) dfs(x+1,y,now+1);
	else if(!vis[x-1][y]&&x-1>=1) dfs(x-1,y,now+1);
	else dfs(x,y+1,now+1);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	memset(vis,false,sizeof(vis));
	cin>>n>>m;
	int kk=n*m;
	//*
	for(int i=1;i<=kk;i++)
	{
		cin>>a[i].z;
		a[i].id=i;
	}
	stable_sort(a+1,a+kk+1,cmp);
	//*/
	dfs(1,1,1);
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	//*/
	int ii=-1;
	for(int i=1;i<=n*m;i++)
	{
		//cout<<a[i].z<<":"<<a[i].id<<endl;
		if(a[i].id==1)
		{
			ii=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(d[i][j]==ii)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}

