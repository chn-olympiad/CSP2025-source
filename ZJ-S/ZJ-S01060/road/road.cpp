#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x7f7f7f7f
const int maxn = 1e4+100,maxm = 1e3+10,Maxm = 1e6+100;
int n,m,k,fa[maxn+100],dis[maxm+10][maxm+10];
int a[20][maxn+100],c[20];
int u[Maxm+100],v[Maxm+100],w[Maxm+100];
int M,ret = 0,val1 = 0;
struct node{int to,dis;};
struct edge{int from,to,v;};
bool cmp(edge A,edge B){
	return A.v < B.v;
}
int findfa(int x){
	if(fa[x] == x) return x;
	return fa[x] = findfa(fa[x]);
}
vector<node> G[maxn+100];
vector<edge> s;
int solve1(){
	for(int i = 1;i <= n;i++) fa[i] = i;
	sort(s.begin(),s.end(),cmp);
	int sum = 0;
	for(int i = 0;i < s.size();i++){
		int x = findfa(s[i].from),y = findfa(s[i].to);
		if(x == y) continue;
		sum += s[i].v;
		fa[x] = y;
		if(sum+val1 > ret) return inf;
	}
	return sum;
}

void solve2(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(j == i) dis[i][i] = 0;
			else dis[i][j] = inf;
		}
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++){
			for(int l = j+1;l <= n;l++){
				dis[j][l] = min(dis[j][l],a[i][j]+a[i][l]);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			if(i != j) s.push_back((edge){i,j,dis[i][j]});
		}
	}
	cout << solve1() << '\n';
	return;
}

void solve3(){
	M = 1ll*(1 << k) - 1,ret = inf;
	for(int i = 0;i <= M;i++){
		val1 = 0;
		for(int ii = 1;ii <= n;ii++)
			for(int jj = ii+1;jj <= n;jj++)
				dis[ii][jj] = inf;
		for(int j = 0;j < k;j++){
			if((i >> j) & 1 == 1){
				val1 += c[j+1];
				for(int ii = 1;ii <= n;ii++){
					for(int jj = ii+1;jj <= n;jj++){
						dis[ii][jj] = min(dis[ii][jj],a[j+1][ii]+a[j+1][jj]);
					}
				}
			}
		}
		s.clear();
		for(int p = 1;p <= m;p++) s.emplace_back((edge){u[p],v[p],w[p]});
		for(int ii = 1;ii <= n;ii++){
			for(int jj = ii+1;jj <= n;jj++){
				s.emplace_back((edge){ii,jj,dis[ii][jj]});
			}
		}
		ret = min(ret,val1+solve1());
	}
	cout << ret << '\n';
	return;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	bool flag = 0;
	for(int i = 1;i <= m;i++){
		cin >> u[i] >> v[i] >> w[i];
		s.push_back((edge){u[i],v[i],w[i]});
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		if(c[i] != 0) flag = 1;
		for(int j = 1;j <= n;j++) cin >> a[i][j];
	}
	if(k == 0){
		cout << solve1() << '\n';
		return 0;
	}
	else if(flag == 0){
		ret = inf;
		solve2();
	}
	else{
		solve3();
	}
	return 0;
}
