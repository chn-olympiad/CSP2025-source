#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 10;
const ll INF = 1e18;

ll n ,m ,k;
struct zy {
	ll u ,v ,w;
}es[N] ,nes[N];
bool cmp(zy a ,zy b) {
	return a.w < b.w;
}
ll val[N] ,k_es[20][N];

ll f[N];
ll find(ll x) {
	if (f[x] == x) {
		return f[x];
	}
	return f[x] = find(f[x]);
}

ll vis[20] ,ans = INF;
void dfs(ll idx) {
	if (idx == k+1) {
		for (register int i=1 ;i<=k ;i++) {
			//cout<<vis[i]<<" ";
		}
		//cout<<" : "<<endl;
		ll tmp = 0;
		ll idxe = m ,cntp = n;
		for (register int i=1 ;i<=m ;i++) {
			nes[i] = es[i];
		}
		for (register int i=1 ;i<=k ;i++) {
			if (vis[i] == 0) {
				continue;
			}
			cntp++;
			tmp += val[i];
			for (register int j=1 ;j<=n ;j++) {
				nes[++idxe] = {i+n ,j ,k_es[i][j]};
				//cout<<i+n<<" "<<j<<" "<<k_es[i][j]<<endl;
			}
		}
		sort(nes+1 ,nes+1+idxe ,cmp);
		ll lt_cnt = 0;
		for (register int i=1 ;i<=cntp ;i++) {
			f[i] = i;
		}
		for (register int i=1 ;i<=idxe ;i++) {
			zy thi = nes[i];
			ll u = nes[i].u ,v = nes[i].v;
			ll nu = find(u) ,nv = find(v);
			if (nu != nv) {
				tmp += nes[i].w;
				if (tmp > ans) {
					return;
				}
				//dcout<<u<<" "<<v<<" "<<es[i].w<<endl;
				lt_cnt++;
				f[nu] = nv;
				if (lt_cnt == cntp-1) {
					break;
				}
			}
		}
		ans = min(ans ,tmp);
		//cout<<tmp<<endl;
		return;
	}
	vis[idx] = 0;
	dfs(idx+1);
	vis[idx] = 1;
	dfs(idx+1);
}

ll flag_a = 1;
int main() {
	freopen("road.in" ,"r" ,stdin);
	freopen("road.out" ,"w" ,stdout);
	scanf("%lld %lld %lld" ,&n ,&m ,&k);
	for (register int i=1 ;i<=m ;i++) {
		ll u ,v ,w;
		scanf("%lld %lld %lld" ,&u ,&v ,&w);
		es[i] = {u ,v ,w};
	}
	for (register int i=1 ;i<=k ;i++) {
		scanf("%lld" ,&val[i]);
		if (val[i] != 0) {
			//cout<<i<<endl;
			flag_a = 0;
		}
		for (int j=1 ;j<=n ;j++) {
			scanf("%lld" ,&k_es[i][j]);
		}
	}
	if (flag_a) {
		//cout<<"Sycamoer_TY"<<endl;
		ll idxe = m ,cntp = n ,tmp = 0;
		for (register int i=1 ;i<=k ;i++) {
			ll aka = 0;
			for (register int j=1 ;j<=n ;j++) {
				if (k_es[i][j] == 0) {
					aka = j;
				}
			}
			for (register int j=1 ;j<=n ;j++) {
				if (j == aka) {
					continue;
				}
				es[++idxe] = {aka ,j ,k_es[i][j]};
			}
		}
		sort(es+1 ,es+1+idxe ,cmp);
		ll lt_cnt = 0;
		for (register int i=1 ;i<=cntp ;i++) {
			f[i] = i;
		}
		for (register int i=1 ;i<=idxe ;i++) {
			zy thi = es[i];
			ll u = es[i].u ,v = es[i].v;
			ll nu = find(u) ,nv = find(v);
			if (nu != nv) {
				tmp += es[i].w;
				//cout<<u<<" "<<v<<" "<<es[i].w<<endl;
				lt_cnt++;
				f[nu] = nv;
				if (lt_cnt == cntp-1) {
					break;
				}
			}
		}
		printf("%lld" ,tmp);
		return 0;
	}
	dfs(1);
	printf("%lld" ,ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 8 4 4
0 100 0 100 100

*/
