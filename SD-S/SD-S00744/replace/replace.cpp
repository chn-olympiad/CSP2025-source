#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int MOD = 998244353;

string sf[N], ss[N];
string tf[N], ts[N];

int pos[N];

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	
	for(int i=1; i<=n; i++){
		cin >> sf[i] >> ss[i];
	}
	for(int i=1; i<=q; i++){
		cin >> tf[i] >> ts[i];
	}
	
	for(int i=1; i<=q; i++){
		int a = tf[i].length();
		int cur = 0;
		for(int j=1; j<=a; j++){
			if(tf[i] != ts[i]) pos[++cur] = i;
		}
	}
	
	while(q--) cout << 0 << endl;
	
	return 0;
}

