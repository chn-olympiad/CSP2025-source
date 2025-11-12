#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e4 , MAXM = 2e6 , MAXK = 20;
int n , m , k , c[MAXK];
int P;
struct Edges{
	int u , v , w;
} e[MAXM];

int f[MAXN];
int find(int fa){
	if (fa != f[fa]) f[fa] = find(f[fa]);
	return f[fa];
}

int ans = 1e18;
unordered_set <int> S;

void calc(int C){
	for (auto it = S.begin() ; it != S.end() ; it ++) if (C & (*it)) return ;
	for (int i = 0 ; i <= n + k ; i ++) f[i] = i;
	int res = 0 , cnt = 0 , USE = 0 , use = 0;
	unordered_set <int> s;
	for (int i = 1 ; i <= k ; i ++){
		if (C & (1 << (i - 1))) res += c[i] , USE ++;
	}
	int cnt1 = 0 , cnt2 = 0;
	for (int i = 1 , u , v , w , fu , fv ; i <= P ; i ++){
		if (cnt1 == n - 1 || cnt1 + cnt2 == n + use - 1) break;
		u = e[i].u , v = e[i].v , w = e[i].w;
		if (u > n && (C & (1 << (u - n - 1))) == 0) continue;
		fu = find(u) , fv = find(v);
		if (fu != fv){
			res += w;
			f[fu] = fv;
			if (u <= n && v <= n) cnt1 ++;
			if (u > n && v <= n){
				cnt2 ++;
				if (!s.count(u)){
					use ++;
					s.insert(u);
				}
			}
		}
	}
	if (use < USE) S.insert(C);
	ans = min(res , ans);
	return ;
}

signed main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin >> n >> m >> k;
	for (int i = 1 ; i <= m ; i ++) ++ P , cin >> e[P].u >> e[P].v >> e[P].w;
	for (int i = n + 1 ; i <= n + k ; i ++){
		cin >> c[i - n];
		for (int j = 1 ; j <= n ; j ++){
			e[++ P] = {i , j , 0};
			cin >> e[P].w;
		}
	}
	sort(e + 1 , e + P + 1 , ([](Edges &x , Edges &y) -> bool{
		return x.w < y.w;
	}));
	for (int C = 0 ; C < (1 << k) ; C ++) calc(C);
	cout << ans;
	return 0;
}
