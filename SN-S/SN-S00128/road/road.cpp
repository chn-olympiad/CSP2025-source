#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int ans = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ans = ans*10 + ch - '0';
		ch = getchar(); 
	}
	return ans*f;
}
struct dsu{
	vector<int> pa,size;
	int count;
	dsu(int n){
		int find(long long x){
			return x == pa[x] ? x : pa[x] == find(pa[x]);
		}
		void merge(long long x,long long y){
			x = find(x),y = find(y);
			if(x==y) return;
			if(size[x]<size[y]) swap(x,y);
			size[x] += size[y];
			count--;
		}
		bool pd(long long x,long long y){
			return find(x) == find(y);
		}
	} 
};
const int N = 1e4 + 10,M = 1e6 + 10;
struct edge{
	long long u,v,w;
	bool operater < (const struct edge& rhs){
		return w < rhs.w;
	}
}e[M+10*N];
long long n,m,k,ans,x;
long long a[N];
void solve(){
	n = read(),m = read(),k = read();
	struct dsu uf(n);
	for(int i=1;i<=m;i++){
		e[i].u = read(),e[i].v = read(),e[i].w = read();
	}
	if(k==0){
		sort(e+1,e+m+1);
		for(int i=1;i<=m;i++){
			if(uf.pd(e[i].u,e[i].v)) continue;
			uf.merge(e[i].u,e[i].v);
			ans += e[i].w;
			if(uf.count==1){
				cout<<ans;
				return;
			}
		}
	}
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){
			x = read();
			e[i+m].w = read();
			e[i+m].u = i+n;
			e[i+m].v = i;
		}
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m+k*n;i++){
		if(uf.pd(e[i].u,e[i].v)) continue;
		uf.merge(e[i].u,e[i].v);
		ans += e[i].w;
		if(uf.count==1){
			cout<<ans;
			return;
		}
	}
	
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t = 1;
//	t = read();
	while(t--){
		solve();
	}
	
	
	return 0;
} 
