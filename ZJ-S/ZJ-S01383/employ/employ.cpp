#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
const int inf = 0x7f7f7f7f;
const int mod = 998244353; 

int cntx,cnty,cntz;
int res;
int n, m;
int flag = 0;

void solve() {
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        char x;
        cin >> x;
        if(x != '1'){
            cout << 0;
            exit(0);
        }
    }
    int res = 1;
    for(int i = 1;i<=n;i++){
        res *= i;
        res %= mod;
    }

    cout << res ;

	return;
}

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	int _ = 1;
	while (_--) {
		solve();
	}

	return 0;
}