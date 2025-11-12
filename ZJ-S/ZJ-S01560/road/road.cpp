#include<iostream>
#include<algorithm>
using namespace std;
struct stu
{
	int x,y,z;
}A[1000005],a[1100005];
int n,m,k,c[15],b[15][10005],vis[15],f[10020];
long long ans = 1e18;
int find(int x)
{
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}
bool cmp(stu u,stu v)
{
	return u.z < v.z;
}
void dfs(int x)
{
	if(x > k)
	{
		long long sum = 0,mm = m;
		for(int i = 1;i <= m;i++) a[i] = A[i];
		for(int i = 1;i <= k;i++)
		{
			if(!vis[i]) continue;
			sum += c[i];
			for(int j = 1;j <= n;j++) a[++mm] = {n + i,j,b[i][j]};
		}
		sort(a + 1,a + mm + 1,cmp);
		for(int i = 1;i <= n + k;i++) f[i] = i;
		for(int i = 1;i <= mm;i++)
		{
			int x = find(a[i].x),y = find(a[i].y);
			if(x != y)
			{
				f[x] = y;
				sum += a[i].z;
			}
		}
		ans = min(ans,sum);
		return;		
	}
	if(vis[x] == 2)
	{
		dfs(x + 1);
		return;
	}
	vis[x] = 1;
	dfs(x + 1);
	vis[x] = 0;
	dfs(x + 1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) cin >> A[i].x >> A[i].y >> A[i].z;
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		if(c[i] == 0) vis[i] = 2;
		for(int j = 1;j <= n;j++) cin >> b[i][j];
	}
	dfs(1);
	cout << ans << "\n";
	return 0;
}
