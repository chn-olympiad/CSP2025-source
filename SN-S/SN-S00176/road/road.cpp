#include <bits/stdc++.h>
#define maxn 10010
#define maxm 1000100
#define ll long long
#define ls (x << 1)
#define rs ((x << 1) | 1)
#define mid ((l + r) >> 1)
#define int long long
//#define freo freopen("road.in","r",stdin);
#define lowbit(x) (x & (-x))
#define IO ios::sync_with_stdio(0);cin.tie(0);
#define inf 0x3f3f3f3f3f3f3f3fll
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
int n,m,k;
struct edge{
	int x,y,w;
}e[maxm + maxn];
bool cmp(edge x,edge y){
	return x.w < y.w;
}
int p[6];
edge c[6][maxn];
edge d[6][maxm + maxn * 6];
int top[6];
int fa[maxn + maxm];
int tans = 0,tres = 0;
int T = 1;
int ans = inf;
void merge(int x,int y){
	int l = 0,r = 0;
	top[y] = 0;
	while(l + 1 <= top[x] && r + 1 <= n){
		if(d[x][l + 1].w < c[y][r + 1].w){
			d[y][++top[y]] = d[x][l + 1];
			l++;
		}else{
			d[y][++top[y]] = c[y][r + 1];
			r++;
		}
	}
	while(l + 1 <= top[x]){
		d[y][++top[y]] = d[x][l + 1];
		l++;
	}
	while(r + 1 <= n){
		d[y][++top[y]] = c[y][r + 1];
		r++;
	}
}
int findfa(int x){
	if(x == fa[x]){
		return x;
	}
	return fa[x] = findfa(fa[x]);
}
int work(){
//	for(int i = 1;i <= top[k];i++){
//		cout << d[k][i].x<<  " " << d[k][i].y <<" "<< d[k][i].w << endl;
//	}
	int tot = 0,now = n + k;
	for(int i = 1;i <= now;i++){
		fa[i] = i;
	}
	for(int i = 1;i <= top[k];i++){
		int tx = findfa(d[k][i].x),ty = findfa(d[k][i].y);
		if(tx != ty){
			fa[tx] = ty;
			tot += d[k][i].w;
			now--;
		}
	}
//	cout << tot << " " <<  tans<< endl;
	return tot + tans;
}
void dfs(int x){
	if(x == k + 1){
		ans = min(ans,work());
		return ;
	}
	top[x] = top[x - 1];
	for(int i = 1;i <= top[x - 1];i++){
		d[x][i] = d[x - 1][i];
	}
	dfs(x + 1);
    merge(x - 1,x);
    tans += p[x];
    tres++;
    dfs(x + 1);
    tans -= p[x];
    tres--;
}
int all = 0;
void solve(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> e[i].x >> e[i].y >> e[i].w;
	}
	sort(e + 1,e + m + 1,cmp);
	for(int i = 1;i <= k;i++){
		int x;
		cin >> p[i];
		bool ch = false;
		for(int j = 1;j <= n;j++){
			cin >> x;
			c[i][j] = {n + i,j,x};
		}
	}
	for(int i = 1;i <= k;i++){
		sort(c[i] + 1,c[i] + n + 1,cmp);
	}
	top[0] = m;
	for(int i = 1;i <= m;i++){
		d[0][i] = e[i];
	}
	dfs(1);
	cout << ans << endl;
}
signed main(){
//	cin >> T;
    IO;
    while(T--){
    	solve();
	}	
	return 0;
}
