#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;

int n;
struct node{
	int a, b, c;
	int dif;
}a[N];
int cnt1, cnt2, cnt3, ans;
int x[N], y[N], z[N];

void solve(int opt, int delta){
	if(opt == 1){
		sort(x + 1, x + cnt1 + 1);
		for(int i = 1; i <= delta; i++)  ans -= x[i];
	}  
	else if(opt == 2){
		sort(y + 1, y + cnt2 + 1);
		for(int i = 1; i <= delta; i++)  ans -= y[i];
	}
	else{
		sort(z + 1, z + cnt3 + 1);
		for(int i = 1; i <= delta; i++)  ans -= z[i];
	}
}

signed main(){
	cin.tie(0) -> sync_with_stdio(0);

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		int mx, mn, mid;
		for(int i = 1; i <= n; i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
			mx = max(a[i].a, max(a[i].b, a[i].c));
			mn = min(a[i].a, min(a[i].b, a[i].c));
			mid = a[i].a + a[i].b + a[i].c - mx - mn;
			a[i].dif = mx - mid;
		}
		cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
		for(int i = 1; i <= n; i++){
			if(a[i].a >= a[i].b && a[i].a >= a[i].c)  x[++cnt1] = a[i].dif, ans += a[i].a;
			else if(a[i].b >= a[i].a && a[i].b >= a[i].c)  y[++cnt2] = a[i].dif, ans += a[i].b;
			else  z[++cnt3] = a[i].dif, ans += a[i].c;
		}
		if((cnt1 <= n / 2) && (cnt2 <= n / 2) && (cnt3 <= n / 2))  cout << ans << "\n";
		else{
			if(cnt1 >= n / 2)  solve(1, cnt1 - n / 2);
			else if(cnt2 >= n / 2)  solve(2, cnt2 - n / 2);
			else  solve(3, cnt3 - n / 2);
			cout << ans << "\n";
		}
	}
	return 0;
}
/*
发现假如某个社团人数大于 n/2，即使把多于 n / 2 的人全部挪到另一个社团也是可以满足的
只需要记录每个人最大值和次大值的差，再按需分配人 
*/
