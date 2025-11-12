#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N],b[N],c[N];
int n,ans = 0,lim;
int dx[] = {1,0,0};
int dy[] = {0,1,0};
int dz[] = {0,0,1};
void dfs(int x,int y,int z,int num,int id)
{
	for(int i = 0;i < 3;i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		int tz = z + dz[i];
		if(tx <= lim && ty <= lim && tz <= lim)
		{
			int tid = id + 1; 
			int tnum = num + dx[i] * a[tid] + dy[i] * b[tid] + dz[i] * c[tid];
			if(tid >= n)
			{
				ans = max(ans,tnum);
				return ;
			}
			dfs(tx,ty,tz,tnum,tid);
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		lim = n / 2;
		for(int i = 1;i <= n;i++)
			cin >> a[i] >> b[i] >> c[i];
		dfs(0,0,0,0,0); // 1,2,3,Êı×Ö
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
