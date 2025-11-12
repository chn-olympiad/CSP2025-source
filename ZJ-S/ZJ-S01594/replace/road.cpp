#include<bits/stdc++.h>
using namespace std;
int n,m,k,coun[11][10005],f[10005],ans,cnt,g[10005][10005],num;
struct edge{
	int u,v,w;
}e[2000006];
int find(int x){
	if(f[x] = x)
		return x;
	else
		return find(f[x]);
}
bool cmp(edge a,edge b){
	return a.w < b.w;
}
void kruskal(){
	for(int i = 1; i <= m; i++){
		int u = e[i].u,v = e[i].v,w = e[i].w;
		int fu = find(u),fv = find(v);
		if(fu != fv){
			ans += w;
			f[fu] = fv;
			cnt++;
			if(cnt >= n - 1)
				break;
		}
	}
}
int main(){
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	
	for(int i = 1; i <= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
		g[e[i].u][e[i].v] = g[e[i].v][e[i].u] = e[i].w; 
	}
	for(int i = 1; i <= n; i++)
		f[i] = i;
	for(int i = 1; i <= k; i++){
		for(int j = 0; j <= n; j++){
			cin >> coun[i][j];
		}
	}
	if(k!=0){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			g[i][j] = 1000000000;
	for(int i = 1; i <= n; i++){
		
		for(int j = 1; j <= n; j++){
			if(i < j){
				int minn=1000000000;
				for(int l = 1; l <= k; l++){
					minn = min(minn, coun[l][i] + coun[l][j]);
				}
				if(minn < g[i][j]){
					num++;
					e[m+num].u = i;
					e[m+num].v = j;
					e[m+num].w = minn;
					
				}
			}
		}
	}
	
	sort(e + 1, e + m + num + 1, cmp);
	kruskal();
	cout << ans;
	
}
	if(k==0){
		sort(e + 1, e + m + 1, cmp);
		kruskal();
		cout << ans;
	}
	return 0;
}
