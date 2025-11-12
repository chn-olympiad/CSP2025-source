#include<bits/stdc++.h>
using namespace std;
#define LL long long
// #define int long long
const int N = 1e4 + 100;
const int M = 1e6 + 30;
struct node{
	int u,v;
	LL w;
};
node e[M];
bool cmp(node a,node b){
	return a.w < b.w;
}
int n,m,k;
LL a[11][N];
LL c[N];
int fa[N];
LL siz[N];
int cnt_l[32],cnt_r[32];
node cho[N];
inline int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
inline void init(){
	for(int i=1;i<=n+k;i++)
		fa[i] = i,siz[i] = 1;
	return ;
}
LL ans = 0;
node E_l[32][N],E_r[32][N];
int len_l[32],len_r[32];
node E_t[N * 10 + N];
LL num_l[32],num_r[32];
inline void calc_l(int x,int len){
	// cout << x << "\n";
	init();
	int tot = n-1;
	for(int i=1;i<n;i++)
		E_t[i] = cho[i];
	for(int i=0;i<len;i++){
		if((x >> i) & 1){
			cnt_l[x] ++ ;
			num_l[x] += (long long)(c[i+1]);
			for(int j=1;j<=n;j++){
				E_t[++tot].u = i+1+n,E_t[tot].v = j,E_t[tot].w = a[i+1][j];
			}
		}
	}
	sort(E_t+1,E_t+1+tot,cmp);
	int cnt = 0;
	for(int i=1;i<=tot;i++){
		if(siz[find(1)] >= n+num_l[x]) break;
		int u,v;
		u = E_t[i].u,v = E_t[i].v;
		u = find(u),v = find(v);
		if(u != v){
			if(siz[u] < siz[v]) swap(u,v);
			siz[u] += siz[v];
			fa[v] = u;
			cnt ++ ;
			E_l[x][cnt] = E_t[i];
		}
	}
	len_l[x] = cnt;
	return ;
}
inline void calc_r(int x,int len,int lst){
	init();
	int tot = n-1;
	for(int i=1;i<n;i++)
		E_t[i] = cho[i];
	for(int i=0;i<len;i++){
		if((x >> i) & 1){
			num_r[x] += (long long)(c[i+1+lst]);
			cnt_r[x] ++;
			for(int j=1;j<=n;j++){
				E_t[++tot].u = i+1+lst+n,E_t[tot].v = j,E_t[tot].w = a[i+1+lst][j];
			}
		}
	}
	sort(E_t+1,E_t+1+tot,cmp);
	// for(int i=1;i<=tot;i++)
		// cout << E_t[i].u << " " << E_t[i].v << " " << E_t[i].w << "\n";
	int cnt = 0;
	// cout << cnt_r[x] << "\n";
	for(int i=1;i<=tot;i++){
		// cout << siz[find(1)] << " ";
		if(siz[find(1)] >= n+cnt_r[x]) break;
		int u,v;
		u = E_t[i].u,v = E_t[i].v;
		u = find(u),v = find(v);
		if(u != v){
			if(siz[u] < siz[v]) swap(u,v);
			cnt ++ ;
			siz[u] += siz[v];
			fa[v] = u;
			E_r[x][cnt] = E_t[i];
		}
	}
	// cout << "\n";
	len_r[x] = cnt;
	// cout << len_r[x] << " ";
	return ;
}
inline void calc(int x,int y){
	// cout << cnt_l[x] << " " << cnt_r[y] << "\n";
	init();
	int tot = len_l[x] + len_r[y];
	for(int i=1;i<=len_l[x];i++)
		E_t[i] = E_l[x][i];
	for(int i=len_l[x]+1;i<=tot;i++)
		E_t[i] = E_r[y][i-n+1];
	sort(E_t+1,E_t+1+tot,cmp);
	LL sum = num_l[x] + num_r[y];
	// cout << x << " " << y << "\n";
	// cout << sum << "\n";
	if(sum > ans) return;
	
	for(int i=1;i<=tot;i++){
		if(siz[find(1)] >= (long long)(n+cnt_l[x]+cnt_r[y])) break;
		int u,v;
		u = E_t[i].u,v = E_t[i].v;
		u = find(u),v = find(v);
		if(u != v){
			if(siz[u] < siz[v]) swap(u,v);
			siz[u] += siz[v];
			fa[v] = u;
			sum += (long long)(E_t[i].w);
			if(sum > ans) return;
		}
	}
	// cout << sum << "\n";
	ans = min(ans,sum);
	return ;

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e+1,e+1+m,cmp);
	init();
	int cnt = 0;
	for(int i=1;i<=m;i++){
		if(cnt == n-1) break;
		int u,v;
		u = e[i].u,v = e[i].v;
		u = find(u),v = find(v);
		if(u != v){
			if(siz[u] < siz[v]) swap(u,v);
			siz[u] += siz[v];
			fa[v] = u;
			cnt ++ ;
			cho[cnt] = e[i];
			ans += (long long)(e[i].w);
		}
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	}
	int mid = k / 2;
	for(int i=0;i<(1<<mid);i++){
		calc_l(i,mid);
		// print_l(i);
 	}
 	for(int i=0;i<(1<<(k-mid));i++){
 		calc_r(i,k-mid,mid);
 	}
 	for(int i=0;i<(1<<mid);i++){
 		for(int j=0;j<(1<<(k-mid));j++){
 			calc(i,j);
 		}
 	}
 	cout << ans;
	return 0;
}