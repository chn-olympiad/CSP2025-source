#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	
	
	int n, q;
	cin >> n >> q;
	unordered_map<string, string> replace;
	for(int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		replace[a] = b;
	}
	
	for(int i = 0; i < q; i++) {
		string a, b;
		cin >> a >> b;
		cout << 0 << endl;
	}
}
