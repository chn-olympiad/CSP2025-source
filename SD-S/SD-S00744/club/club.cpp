#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int MOD = 998244353;

int q;

int n;
struct Node{
	int a, b, c;
}r[N];

bool cmp1(Node x, Node y){
	return x.a < y.a;
}
bool cmp2(Node x, Node y){
	return x.c < y.c;
}
bool cmp3(Node x, Node y){
	return x.b < y.b;
}

void solve(){
	cin >> n;
	bool flagA = 1, flagB = 1;
	for(int i=1; i<=n; i++){
		cin >> r[i].a >> r[i].b >> r[i].c;
		if(r[i].b != 0){
			flagA = 0;
		}
		if(r[i].c != 0){
			flagA = flagB = 0;
		}
	}
	if(flagA){
		sort(r+1, r+n+1, cmp1);
		int ans = 0;
		for(int i=n; i>=n/2+1; i--){
			ans += r[i].a;
		}
		cout << ans << endl;
		return;
	}
	if(flagB){
		for(int i=1; i<=n; i++){
			r[i].c = r[i].a - r[i].b;
		}
		sort(r+1, r+n+1, cmp2);
		int ans = 0;
		for(int i=n; i>=n/2+1; i--){
			ans += r[i].a;
		}
		for(int i=n/2; i>=1; i--){
			ans += r[i].b;
		}
		cout << ans << endl;
		return;
	}
	cout << 0 << endl;
	return;
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> q;
	while(q--){
		solve();
	}
	
	return 0;
}

