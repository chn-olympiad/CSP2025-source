#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 10;
template<typename TY>
inline void read(TY &s){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	s = x * f;
}
int n;
ll a[N][5];
bool vis[N];
int cnt[5];
struct node{
	ll w; int id,pos;
};
bool operator<(const node &x,const node &y){
	return x.w < y.w;
}
ll ans;
map<int,map<int,bool> > mp[N];
void dfs(int pos,ll sum,int c1,int c2,int c3){
	if(c1 > n/2 || c2 > n/2 || c3 > n/2) return;
	if(pos == n + 1){
		ans = max(ans,sum);
		return;
	} 
	if(c1 < n/2) dfs(pos+1,sum+a[pos][1],c1+1,c2,c3);
	if(c2 < n/2) dfs(pos+1,sum+a[pos][2],c1,c2+1,c3);
	if(c3 < n/2) dfs(pos+1,sum+a[pos][3],c1,c2,c3+1);
}
void solve(){
	priority_queue<node> Q;
	for(int i=1;i<=n;i++) vis[i] = false; 
	for(int i=1;i<=3;i++) cnt[i] = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			Q.push({a[i][j],i,j});
		}
	}
	ll ans = 0;
	while(!Q.empty()){
		auto u = Q.top(); Q.pop();
		ll val = u.w; int ps = u.pos, idx = u.id;
		if(vis[idx]) continue;
		if(cnt[ps] >= n/2) continue;
		cnt[ps]++; ans += val; vis[idx] = true;
	}
	cout << ans << "\n";
}
void solve_A(){
	vector<int> p;
	for(int i=1;i<=n;i++){
		p.push_back(a[i][1]);
	}
	sort(p.begin(),p.end());
	ll res = 0,cc = 0;
	for(int i = p.size()-1;i>=0;i--){
		if(cc >= n/2) break;
		res += p[i];
		cc++;
	}
	cout << res << "\n";
}
void solve_dfs(){
	bool f = false;
	read(n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			read(a[i][j]);
		}
		if(a[i][2] || a[i][3]) f = true;
	}
	if(!f){
		solve_A();
		return;
	}
	if(n <= 15){
		ans = 0;
		dfs(1,0,0,0,0);
		cout << ans << "\n";
		return;
	}
	solve();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	read(T);
	while(T--) solve_dfs();
	return 0;
}
