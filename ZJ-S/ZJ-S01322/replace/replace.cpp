#include<bits/stdc++.h>
using namespace std;
string a[300000], b[300000];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int qq = 1; qq <= q; qq++) {
		int sum = 0;
		string to, want;
		cin >> to >> want;
		for (int i = 0; i < want.length(); i++) {
			for (int j = 1; j <= n; j++) {
				bool f = false;
				for (int k = 0; k < a[j].length(); k++) {
					if (a[j][k] != to[i+k]) {
						f = true;
						break;
					}
				}
				if (f) continue;
				string news = to;
				for (int k = 0; k < a[j].length(); k++) {
					news[k+i] = b[j][k];
				}
				if (news == want) sum ++;
			}
		}
		cout << sum << '\n';
	}
	
	
	
	
	
	
	return 0;
}
