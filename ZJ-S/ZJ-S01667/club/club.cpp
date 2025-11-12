#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
struct A{
	int v, id;
	bool operator<(const A &p)const{
		return v > p.v;
	}
}a[N][4];
int n, t[4], b[N];
void solve(){
	for(int i = 1; i <= 3; i++)	t[i] = 0;
	int ans = 0, cnt = 0;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			scanf("%lld", &a[i][j]);
			a[i][j].id = j;
		}
		sort(a[i] + 1, a[i] + 4);
		t[a[i][1].id]++;
		ans += a[i][1].v;
	}
	if(t[1] <= n / 2 && t[2] <= n / 2 && t[3] <= n / 2){
		printf("%lld\n", ans);
		return;
	}
	for(int op = 1; op <= 3; op++){
		if(t[op] > n / 2){
			for(int i = 1; i <= n; i++){
				if(a[i][1].id == op){
					b[++cnt] = a[i][1].v - a[i][2].v;
				}
			}
			sort(b + 1, b + 1 + cnt);
			for(int i = 1; i <= t[op] - n / 2; i++)	ans -= b[i];
			printf("%lld\n", ans);
			return;
		}
	}
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%lld", &T);
	while(T--)	solve();
	return 0;
}
