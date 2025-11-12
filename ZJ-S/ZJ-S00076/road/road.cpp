#include <bits/stdc++.h>
#define int long long
using namespace std;
int fa[11000],c[12],totg;
struct Dat{
	int x,y,z;
}e[1000010],edge[1000010],ne[12][1010],g[1010];
int n,m,k;
int root(int x){
	if(fa[x] == x)return x;
	fa[x] = root(fa[x]);
	return fa[x];
}
bool cmp(Dat xx,Dat yy){
	return xx.z < yy.z;
}
int Readd(){
	int s = 0;char c = getchar();int f = 1;
	for(; c < '0' || c > '9'; c = getchar())(c == '-') && (f = -1);
	for(; c >= '0' && c <= '9'; c = getchar())s = (s << 1) + (s << 3) + (c ^ 48);
	return s * f;
}
void solve(){
	//cout << "*";
	sort(e + 1,e + m + 1,cmp);
	for(int i = 1; i <= n; i++)fa[i] = i;
	for(int i = 1; i <= m; i++){
		int x = root(e[i].x),y = root(e[i].y);
		if(x != y)fa[x] = y,g[++totg] = e[i];
	}
	int cst = 0,tot = 0;
	for(int j = 1; j <= n + k; j++)fa[j] = j;
	for(int j = 1; j < n; j++)edge[++tot] = g[j];
	for(int j = 1; j <= k; j++){
		for(int l = 1; l <= n; l++){
			edge[++tot] = ne[j][l];
			//cout << ne[j][l].z << endl;
		}
	}
	//cout << tot << endl;
	sort(edge + 1,edge + tot + 1,cmp);
	for(int j = 1; j <= tot; j++){
		int x = root(edge[j].x),y = root(edge[j].y);
		if(x != y)fa[x] = y,cst += edge[j].z;
	}
	printf("%lld",cst);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = Readd(),m = Readd(),k = Readd();
	for(int i = 1; i <= m; i++){
		e[i].x = Readd(),e[i].y = Readd(),e[i].z = Readd();
	}
	bool fl = true;
	for(int i = 1; i <= k; i++){
		c[i] = Readd();
		if(c[i])fl = false;
		for(int j = 1; j <= n; j++){
			ne[i][j].x = i + n,ne[i][j].y = j;
			ne[i][j].z = Readd();
		}
	}
	if(fl){
		solve();
		return 0;
	}
	sort(e + 1,e + m + 1,cmp);
	for(int i = 1; i <= n; i++)fa[i] = i;
	for(int i = 1; i <= m; i++){
		int x = root(e[i].x),y = root(e[i].y);
		if(x != y)fa[x] = y,g[++totg] = e[i];
	}
	int ans = 1e18;
	for(int i = 0; i < (1 << k); i++){
		int cst = 0,tot = 0;
		for(int j = 1; j <= n + k; j++)fa[j] = j;
		for(int j = 1; j < n; j++)edge[++tot] = g[j];
		for(int j = 1; j <= k; j++){
			if(1 & (i >> (j - 1))){
				cst += c[j];
				for(int l = 1; l <= n; l++){
					edge[++tot] = ne[j][l];
					//cout << ne[j][l].z << endl;
				}
			}
		}
		//cout << tot << endl;
		sort(edge + 1,edge + tot + 1,cmp);
		for(int j = 1; j <= tot; j++){
			int x = root(edge[j].x),y = root(edge[j].y);
			if(x != y)fa[x] = y,cst += edge[j].z;
		}
		ans = min(ans,cst);
	}
	printf("%lld",ans);
	return 0;
}