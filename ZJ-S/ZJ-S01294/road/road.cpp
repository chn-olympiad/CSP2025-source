#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+100;
namespace zjcex {
	template<typename T>void _read(T &x) {
		char ch=getchar();
		int tmp=0;
		x=0;
		if(ch=='-') {
			tmp=1;
			ch=getchar();
		}
		while('0'<=ch&&ch<='9') {
			x=(x<<1)+(x<<3)+(ch^(48));
			ch=getchar();
		}
		if(tmp==1) x=-x;
	}
	void read() {}
	
	template<typename T>void read(T &x) {
		_read(x);
	}
	template<typename T>void read(T &x,T &y) {
		_read(x);
		_read(y);
	}
	template<typename T>void read(T &x,T &y,T &z) {
		_read(x);
		_read(y);
		_read(z);
	}
	template<typename T>void read(T *l,T *r) {
		T *cur=l;
		while(cur!=r) {
			_read(*cur);
			cur++;
		}
	}
	template<typename T>void _write(T x) {
		int tmp=0;
		if(x<0) {
			putchar('-');
			x=-x;
		}
		if(x>=10) {
			_write(x/10);
		}
		putchar((x%10)+48);
	}
	template<typename T>void write(T x) {
		_write(x);
		putchar(' ');
	}
	template<typename T>void write(T *l,T *r) {
		T *cur=l;
		while(cur!=r) {
			_write(*cur);
			putchar(' ');
			cur++;
		}
		putchar('\n');
	}
}
void hey() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
using namespace zjcex;
int n,m,k;
int fa[10005];
struct str{
	int u,v,w;
};
vector<str>ve;
vector<int> contry[15];
int cost[15];
vector<int> chosen;
bool cmp(str x,str y) {
	return x.w<y.w;
}
int find(int x) {
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int mmax=INT_MAX;
void gosolve() {
	for(int i=1;i<=n+k;i++) {fa[i]=i;}
	int bost=0;
	vector<str>g;
	for(int i=0;i<ve.size();i++) {
		int a=ve[i].u;
		int b=ve[i].v;
		int c=ve[i].w;
		g.push_back({a,b,c});
	}
	for(int i=0;i<chosen.size();i++) {
		bost+=cost[chosen[i]];
		for(int j=0;j<contry[chosen[i]].size();j++) {
			g.push_back({chosen[i]+n,j+1,contry[chosen[i]][j]});
		}
	}
	sort(g.begin(),g.end(),cmp);
	for(int i=0;i<g.size();i++) {
		int x=g[i].u;
		int y=g[i].v;
		int co=g[i].w;
		int fx=find(x),fy=find(y);
		if(fx!=fy) {
			fa[fx]=fy;
			bost+=co;
		}
	}
	mmax=min(bost,mmax);
}
void dfs(int x) {
	if(x>k) {
		gosolve();
		return;
	}
	dfs(x+1);
	chosen.push_back(x);
	dfs(x+1);
	chosen.pop_back();
}
bool check() {
	for(int i=1;i<=k;i++) {
		if(cost[i]!=0) return 0;
	}
	return 1;
}
signed main() {
	hey();
	read(n,m,k);
	for(int i=1;i<=m;i++) {
		int u,v,w;
		read(u,v,w);
		ve.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++) {
		read(cost[i]);
		for(int j=1;j<=n;j++) {
			int x;
			read(x);
			contry[i].push_back(x);
		}
	}
	if(check()) {
		for(int i=1;i<=k;i++) {
			chosen.push_back(i);
		}
		gosolve();
		write(mmax);
		return 0;
	}
	dfs(1);
	write(mmax);
	return 0;
}
