#include <bits/stdc++.h>
#define int long long
#define all(container) (container.begin()),(container.end())
using namespace std;
const int N = 1e4 + 500;
const int M = 1e6 + 500;
int n,m,k,c[15],a[15][N];
struct edge{
 	int x,y,w;	
 	bool operator < (const edge & rhs) const{
 		if(w == rhs.w){
 			if(x == rhs.x){
 				return y < rhs.y;
			}
			return x < rhs.x;
		}
 		return w < rhs.w;	
	}
	void print(){
		cout << "(" << x << " , " << y << " , " << w << ")" << " ";
	}
};
vector<edge> E,AE,BE,e[15],f[1025];
int dp[1025],fa[N],siz[N],popc[N],sumc[N];
inline int find(int x){
	return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}
inline bool merge(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx == fy)return false;
	if(siz[fx] < siz[fy])swap(x,y),swap(fx,fy);
	fa[fy] = fx;siz[fx] += siz[fy];
	return true;
}
inline int lowbit(int x){
	return x & (-x);
}
void check(vector<edge> v,int code){
	for(int i = 1;i < (int)v.size();i ++){
		if(v[i] < v[i - 1]){
			exit(code);
		}
	}
}
int Kruskal(int ppk,vector<edge> edg,vector<edge> &res){ // must keep edg ordered
	res.clear();
//	check(edg,-2);
	int ans = 0;
	int realn = n + ppk;
	for(int i = 1;i <= n + k;i ++){
		fa[i] = i;
		siz[i] = 1;
	}
	int cnt = 0;
	for(auto ed : edg){
		int x = ed.x,y = ed.y,w = ed.w;
		if(merge(x,y)){
			cnt ++;
			ans += w;
			res.push_back({x,y,w});
		}
		if(cnt == realn - 1){
//			check(res,-3);
			return ans;
		}
	}
//	check(res,-3);
//	cout << "MST create failed." << endl;
//	cout << "ppk = " << ppk << endl;
//	
//	for(auto x : edg){
//		x.print();
//	}
//	exit(-1);
	return -1;
}
vector<edge> Merge(vector<edge> des,vector<edge> src){ //must keep them ordered
//	cout << "des = " << endl;
//	for(auto x : des){
//		x.print();
//	}
//	cout << endl;
//	cout << "src = " << endl;
//	for(auto x : src){
//		x.print();
//	}
//	cout << endl;
	int nn = des.size(),mm = src.size(),p = 0,q = 0;
	vector<edge> res;
	for(int i = 0;i < nn + mm;i ++){
		if(p < nn && q < mm){
			res.push_back(min(des[p],src[q]));
			if(des[p] < src[q])p ++;
			else q ++;
		}else if(p < nn && q >= mm){
			res.push_back(des[p]);
			p ++;
		}else {
			res.push_back(src[q]);
			q ++;
		}
	}
//	vector<edge> ano;
//	for(auto x : des)ano .push_back(x);
//	for(auto x : src)ano .push_back(x);
//	sort(all(ano));
//	
//	assert((res.size() == nn + mm));
//	cout << "res = " << endl;
//	for(auto x : res){
//		x.print();
//	}
//	cout << endl;
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++){
		int u,v,w;
		cin >> u >> v >> w;
		E.push_back({u,v,w});
	}
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
//		int minn = 1e18;
		for(int j = 1;j <= n;j ++){
			cin >> a[i][j];
			e[i].push_back({n + i,j,a[i][j]});
//			minn = min(minn,a[i][j]);
		}
		sort(all(e[i]));
//		if(minn)exit(5);
	}
	sort(all(E));
	dp[0] = Kruskal(0,E,f[0]);
	int ans = dp[0];
//	AE = E;
//	for(int i = 1;i <= k;i ++){
//		for(auto x : e[i]){
//			AE.push_back(x);
//		}
//	}
//	BE = E;
//	for(int i = 1;i <= k;i ++){
//		for(auto x : e[i]){
//			
//		}
//	}
//	cout << AE.size() - k * n - m << endl;
//	cout << Kruskal(k,AE,AE) << endl;
	for(int state = 1;state < (1 << k);state ++){
		int mask = lowbit(state),i = __lg(mask) + 1,src = state - mask;
		popc[state] = popc[src] + 1;sumc[state] = sumc[src] + c[i];
		dp[state] = Kruskal(popc[state],Merge(f[src],e[i]),f[state]);
		ans = min(ans,dp[state] + sumc[state]);
//		cout << "find : " << "state = " << state << " MST: " << dp[state] << 
//		"   cost = " << sumc[state] << "src = " << src << endl; 
//		cout << "f : " << endl;
//		for(auto x : f[state]){
//			x.print();
//		}
//		cout << endl;
	}
//	cout << dp[(1 << k) - 1] << endl;
	cout << ans << endl;
	return 0;
}
