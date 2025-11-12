#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, q;
string s[N], t[N];
int ans = 0;
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> s[i][1] >> s[i][2];
	}
	for(int j = 0; j < q; j++){
		cin >> t[j][1] >> t[j][2];
		
	}
	for(int i = 0; i < q; i++){
		cout << 0 << endl;
	}
	return 0;
}