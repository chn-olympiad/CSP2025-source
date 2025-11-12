#include<bits/stdc++.h>
#define ll long long
#define fff(i, a, b) for(ll i = a; i <= b; ++i)

using namespace std;

int innum(int x){
	return '0' <= x && x <='9';
}
ll read(){
	ll c = getchar(), res = 0, f = 1;
	for(; !innum(c); c = getchar()) if(c =='-') f = -1;
	for(;  innum(c); c = getchar()) res = res * 10 + c -'0';
	return res * f;
}

const ll N = 2000022;
ll lis[10022], fa[10022];
ll n, m, k, tot;

struct edge{
	ll s, e, c;
	edge(){}
	edge(ll _s, ll _e, ll _c){
		s = _s;
		e = _e;
		c = _c;
	}
	friend bool operator < (edge a, edge b){
		return a.c < b.c;
	}
}ed[N];

ll fi(ll x){
	if(fa[x] != x) fa[x] = fi(fa[x]);
	return fa[x];
}

ll uni(ll x, ll y){
	x = fi(x);
	y = fi(y);
	ll res = (fa[x] != y);
	fa[x] = y;
	return res;
}

ll kruskal(){
	sort(ed + 1, ed + tot + 1);
	fff(i, 1, n){
		fa[i] = i;
	}
	ll res = 0;
	fff(i, 1, tot){
		res += uni(ed[i].s, ed[i].e) * ed[i].c;
	}
	return res;
}

int main(){
	freopen("road.in" ,"r", stdin);
	freopen("road.out","w", stdout);
	n = read();
	m = read();
	k = read();
	fff(i, 1, m){
		ll s = read(), e = read(), c = read();
		ed[++tot] = edge(s, e, c);
	}
	fff(i, 1, k){
		ll c = read(), zp = 0;
		fff(j, 1, n){
			lis[j] = read();
			if(lis[j] == 0)zp = j;
		}
		fff(j, 1, n){
			ed[++tot] = edge(zp, j, lis[j]);
		}
	}
	cout << kruskal();
	return 0;
}

/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 8 2 4
0 1 0 2 4






*/

