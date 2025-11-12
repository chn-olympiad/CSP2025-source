#include <bits/stdc++.h>
using namespace std;

const int N = 10100, M = 2000010;

int n, m, k, fa[N], a[14][N], c[100], p[N];
vector<int>chosen;
long long ans = 1e18;

int find(int x)
{
	if(x != fa[x])return fa[x] = find(fa[x]);
	return x;
}
struct tree
{
	int u,v,w;
}tr[N],ee[N];

void init( )
{
	for(int i = 1;i <= n + k * n;i ++)fa[i] = i;
}
bool cmp(tree a,tree b)
{
	return a.w < b.w;
}

void dfs(int size,int cur)
{
	if(chosen.size() < size && chosen.size() + n - cur < size)return;
	if(cur >= size && chosen.size() < size)return;
	if(chosen.size() >= size)
	{
		long long cnt = 1, res = 0;
		
		for(int i = 0;i < chosen.size();i ++)
		{
			int q = chosen[i];
			for(int j = 1;j <= n;j ++)
			{
				ee[n + cnt] = {j,n + i + 1,a[q][j]}	;
				cnt ++;
			}
//			cout << "############\n";
			res += c[q];
		}
		init();
		sort(ee + 1,ee + 1 + n + chosen.size() * n,cmp);
		for(int i = 1;i <= n + n * size;i ++)
		{
			int x = ee[i].u,y = ee[i].v;
			if(find(x) != find(y))
			{
				fa[find(y)] = find(x);
				res += ee[i].w;
//				cout << x << " " << y << " " << ee[i].w << endl;
			}
		}
		ans = min(ans,res);
	//	cout << res << endl;
//		puts("------------------------");
		return;
	}	
	
	chosen.push_back(cur + 1);
	dfs(size,cur + 1);
	chosen.pop_back();
	
	dfs(size,cur + 1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i = 1;i <= m;i ++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		tr[i] = {u,v,w};
	}
	bool A = true;
	
	for(int i = 1;i <= k;i ++)
	{
		cin >> c[i];
		if(c[i] != 0) A = false;
		for(int j = 1;j <= n;j ++)
			scanf("%d",&a[i][j]);
	}
	init();
	
	if(A && k != 0)
	{
		int cnt = 1;
		for(int i = 1;i <= k;i ++)
			for(int j = 1;j <= n;j ++){
				tr[n + cnt] = {j,n + i,a[i][j]};
//				printf("%d %d %d\n",j,n + i,a[i][j]);
				cnt ++;
			}
		sort(tr + 1,tr + 1 + n + k * n,cmp);
		
		for(int i = 1;i <= n + n * k;i ++)
		{
			int x = tr[i].u,y = tr[i].v;		
			if(find(x) != find(y))
			{
				fa[find(y)] = find(x);
				ans += tr[i].w;
	//			cout << x << " " << y << " " << tr[i].w << endl;
			}
		}
//		for(int i = 1;i <= n + k;i ++)cout << fa[i] << " ";
//		cout << endl;
		
		cout << ans << endl;
		return 0;
	}
	
	sort(tr + 1,tr + 1 + n ,cmp);
	for(int i = 1;i <= n;i ++)
	{
		int x = tr[i].u,y = tr[i].v;
		if(find(x) != find(y))
		{
			fa[find(y)] = find(x);
			ans += tr[i].w;
		}
	}
	
	if(k == 0)
	{
		cout << ans << endl;
		return 0;
	}
	for(int i = 1;i <= k;i ++){
//		printf("%d : \n\n\n",i);
		init();
		memcpy(ee,tr,sizeof ee);
		
		dfs(i,0);
		
	}
	cout << ans << endl;
	
	return 0;
}
