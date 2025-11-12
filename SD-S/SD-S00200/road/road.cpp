#include <bits/stdc++.h>
using namespace std;
#define getc getchar
inline long long read(){
	char c = getc() , f = 1;
	while (c > '9' || c < '0'){
		if (c == '-')f = -1;
		c = getc();
	}
	long long p = 0;
	while (c >= '0' && c <= '9'){
		p = p * 10 + c - '0';
		c = getc();
	}
	return p * f;
}
bool sd , f[15];
int n , m , k , num , c[15];
long long ans , sum[15] , sumc;
inline bool rd(){
	sd ^= 1;
	return sd;
}
struct node{
	int u , v , val , id;
	bool friend operator < (const node &a , const node &b){return a.val < b.val;}
}e[2000005];
struct dsu{
	int fa[20005];
	inline void clear(){for (int i = 0;i <= n + k;++i)fa[i] = i;}
	int find_fa(int u){
		if (fa[u] == u)return u;
		return fa[u] = find_fa(fa[u]);
	}
	inline bool merge(int u , int v){
		int fu = find_fa(u) , fv = find_fa(v);
		if (fu == fv)return 0;
		if (rd())fa[fu] = fv;
		else fa[fv] = fu;
		return 1;
	}
}b;
inline long long mst(){
	long long ans = 0;
	int cnt = n - 1;
	for (int i = 1;i <= k;++i){
		if (f[i]){
			ans += c[i];
			cnt++;
		}
	}
	b.clear();
	for (int i = 1;i <= num;++i){
		if (!f[e[i].id])continue;
		if (b.merge(e[i].u , e[i].v)){
			ans += e[i].val;
			cnt--;
			if (!cnt || ans >= ::ans)break;
		}
	}
	return ans;
}
signed main(){
	freopen ("road.in" , "r" , stdin);
	freopen ("road.out" , "w" , stdout);
	n = read() , m = read() , k = read();
	for (int _ = 1;_ <= m;++_){
		num++;
		e[num].u = read();
		e[num].v = read();
		e[num].val = read();
		e[num].id = 0;
	}
	sort (e + 1 , e + num + 1);
	b.clear();
	for (int i = 1;i <= num;++i){
		if (!b.merge(e[i].u , e[i].v))e[i].val = 0x3f3f3f3f;
		else ans += e[i].val;
	}
	sort (e + 1 , e + num + 1);
	num = n - 1;
	//for (int i = 1;i < n;++i)printf ("	%d %d %d\n" , e[i].u , e[i].v , e[i].val);
	for (int i = 1;i <= k;++i){
		c[i] = read();
		for (int j = 1;j <= n;++j){
			num++;
			e[num].u = i + n;
			e[num].v = j;
			e[num].val = read();
			e[num].id = i;
		}
	}
	sort (e + 1 , e + num + 1);
	//for (int i = 1;i <= num;++i)printf ("	%d %d %d %d\n" , e[i].u , e[i].v , e[i].val , e[i].id);
	f[0] = 1;
	for (int s = 1;s < (1 << k);++s){
		for (int i = 1;i <= k;++i){
			if (s & (1 << (i - 1)))f[i] = 1;
			else f[i] = 0;
		}
		ans = min(ans , mst());
	}
	printf ("%lld" , ans);
	return 0;
}
