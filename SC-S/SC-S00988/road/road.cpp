#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
int n, m, k, tot, ans, vg[15], vgf[15], mp[N][15], f[N];
struct edge{
	int bh, fm, to, v, flag;
	friend bool operator < (edge a, edge b){
		if(a.flag != 0 && vgf[a.flag] == 1) return a.v + vg[a.flag] > b.v;
		if(b.flag != 0 && vgf[b.flag] == 1) return a.v > b.v + vg[b.flag];
		else return a.v > b.v;
	}
}b[M];
priority_queue<edge> q;
int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		b[++tot].fm = x;
		b[tot].to = y;
		b[tot].v = z; 
		b[tot].bh = tot;
		b[tot].flag = 0;
		q.push(b[tot]);
	}
	for(int i = 1; i <= k; i++){
		cin >> vg[i];
		vgf[i] = 1;
		for(int j = 1; j <= n; j++){
			int x;
			cin >> x;
			mp[j][i] = x;
		}
		for(int j = 1; j <= n; j++){
			for(int l = j + 1; l <= n; l++){
				b[++tot].fm = j;
				b[tot].to = l;
				b[tot].v = mp[j][i] + mp[l][i];
				b[tot].flag = i;
				b[tot].bh = tot;
				q.push(b[tot]);
			}
		}
	}
	while(!q.empty()){
		int i = q.top().bh;
		q.pop();
		int fx = find(b[i].fm);
		int fy = find(b[i].to);
		if(fx == fy) continue;
		else{
			if(b[i].flag != 0 && vgf[b[i].flag] == 1){
				ans += vg[b[i].flag];
				vgf[b[i].flag] = 0;
			}
			ans += b[i].v;
			f[fx] = fy;
		}
	}
	cout << ans;
	return 0;
}