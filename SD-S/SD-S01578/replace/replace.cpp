#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	int res = q;
	while (q--){
		string a;
		for (int i = 0; i < n; ++i) cin >> a;
		for (int j = 0; j < q; ++j) cin >> a;
		cout << res << '\n';
	}
	return 0;
}
