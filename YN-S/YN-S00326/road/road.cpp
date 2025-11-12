#include <bits/stdc++.h>
using namespace std;
#define For(x,y,z) for(int x = y;x <= z;x++)
using ll = long long;

inline int read() {
	int x = 0, f = 1;char ch;
	while((ch = getchar()) < '0' || ch > '9') if(ch == '-') f = -1;
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

inline ll readl() {
	ll x = 0, f = 1;char ch;
	while((ch = getchar()) < '0' || ch > '9') if(ch == '-') f = -1;
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

int n,m,k;

struct edge{
	int u,v,w;
	bool operator<(const edge &rhs) const{
		return w < rhs.w;
	}
}ed[30000010];

int fa[100010];
int get(int x){
	return fa[x] == x?x:fa[x] = get(fa[x]);
}

int use;
int cou;

inline ll kurs(){
	ll ans = 0;
	int r = 0;
	For(i,1,m){
		int u = ed[i].u,v = ed[i].v,w = ed[i].w;
		if((u <= n || (use & (1 << (u-n-1)))) && get(ed[i].u) != get(ed[i].v)){
			ans += ed[i].w;
			r++;
			fa[get(ed[i].u)] = get(ed[i].v);
		}
		if(r == cou-1) break;
	}
	return ans;
}

ll c[200];
int a[20][100010];
ll cnr[5000];

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//cerr << sizeof(ed)/1024.0/1024;
	ios::sync_with_stdio(0);
//	freopen("road.err","w",stderr);
	n=read(),m=read(),k=read();
	For(i,1,n) fa[i] = i;
	For(i,1,m){
		ed[i] = {read(),read(),read()};
	}
	if(k == 0){
		sort(ed+1,ed+m+1);
		cout << kurs();
		return 0;
	}
	ll ans = LLONG_MAX;
	For(i,1,k){
		c[i]=read();
//		cerr << c[i] << ' ';
		For(j,1,n){
			a[i][j] = read();
			ed[++m] = {i+n,j,a[i][j]};
		}
	}
//	cerr << endl;
	sort(ed+1,ed+m+1);
	int size = (1 << k)-1;
//	cout << m << ' ' << size << endl;
//	For(i,1,k) cerr << c[i] << endl;
	For(i,0,size){
		ll res = 0;
		cou = n;
		For(j,1,k){
			if(i & (1 << (j-1))){
				res += c[j];
				cou++;
//				cerr << j << ' ' << c[j] << endl;
			}
		}
		use = i;
		For(j,1,n+k) fa[j] = j;
//		cerr << res << " ";
		ans = min(ans,kurs()+res);
//		cerr << ans << endl;
	}
	cout << ans;
	return 0;
}