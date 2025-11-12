#include<bits/stdc++.h>
#define int long long
const int N = 1e6+5;
using namespace std;
int n,m,k,a[15][10005],fa[10005],siz[10005],c[15];
struct Way{
	int u,v,w;
}way[N],road[N*2];

bool cmp(Way x,Way y){
	return x.w < y.w;
}

int find(int x){
	if(fa[x]==x)return x;
	return fa[x] = find(fa[x]);
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++)
		cin >> way[i].u >> way[i].v >> way[i].w;
	for(int j = 1;j<=k;j++){
		cin >> c[j];
		for(int i = 1;i<=n;i++)
			cin >> a[j][i];
	}
		
	int mm = m;
	int ans = 1e18;
	for(int s = 0;s<(1<<k);s++){//每一种选点
		mm = m; 
		for(int i = 1;i<=m;i++){
			road[i].u = way[i].u;
			road[i].v = way[i].v;
			road[i].w = way[i].w;
		}
		int point = 0;int sum = 0;
 		for(int i = 0;i<k;i++){
			if(s&(1<<i)){
				sum += c[i+1];
				++point;
				for(int j = 1;j<=n;j++){
					road[++mm].u = n+i+1;
					road[mm].v = j;
					road[mm].w = a[i+1][j];
				}
			}
		}
		sort(road+1,road+mm+1,cmp);
		for(int i = 1;i<=n+k;i++)fa[i] = i,siz[i] = 1;
		int edge = 0;
		for(int i = 1;i<=mm;i++){
			int u = road[i].u;
			int v = road[i].v;
			int w = road[i].w;
			int fu = find(u),fv = find(v);
			if(fu!=fv){
				sum += w;
				if(siz[fu]<siz[fv]){
					fa[fu] = fv;
					siz[fv] += siz[fu];
				}else{
					fa[fv] = fu;
					siz[fu] += siz[fv];
				} 
				edge++;
			}
			if(edge == n+point-1)break;
		}
		ans = min(ans,sum);
//		cout << ans << "\n";
	}
	cout << ans;
}
/*
15:35 [32,48]
*/
