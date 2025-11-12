#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, q;
map<string, string> mp;
int a[200005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string x, y;
		cin >> x >> y;
		mp[x] = y;
		int len = x.size();
		int aim1, aim2;
		for (int i = 0; i < len; i++) {
			if (x[i] == 'b') {
				aim1 = i;
				break;
			}
		}
		for (int i = 0; i < len; i++) {
			if (y[i] == 'b') {
				aim2 = i;
				break;
			}
		}
		if (aim1 > aim2) a[i] = aim1 - aim2;
		else a[i] = aim2 - aim1; 
	}
	while (q--) {
		string x, y;
		cin >> x >> y;
		int len = x.size();
		int ca = 0, cb = 0;
		bool f = 0;
		for (int i = 1; i <= len; i++) {
			if (x[i] == 'a') ca++;
			if (x[i] == 'b') cb++;
		}
		if (cb == 1 && ca + cb == len) f = 1;
		ca = 0, cb = 0;
		for (int i = 1; i <= len; i++) {
			if (y[i] == 'a') ca++;
			if (y[i] == 'b') cb++;
		}
		if (f && cb == 1 && ca + cb == len) {
			int aim1, aim2;
			for (int i = 0; i < len; i++) {
				if (x[i] == 'b') {
					aim1 = i;
					break;
				}
			}
			for (int i = 0; i < len; i++) {
				if (y[i] == 'b') {
					aim2 = i;
					break;
				}
			}
			int yt;
			if (aim1 > aim2) yt = aim1 - aim2;
			else yt = aim2 - aim1;
			int ans = 0;
			for (int i = 1; i <= n; i++) if (a[i] == yt) ans++;
			cout << ans << '\n'; 
			continue;
		}
		int ans = 0;
		string now1, now2;
		for (int i = 0; i < len; i++) {
			now1 = "", now2 = "";
			for (int j = i; j < len; j++) {
				now1 += x[j];
				now2 += y[j];
				if (mp[now1] == now2) {
					bool f = 0;
					for (int k = 0; k < i; k++) if (x[k] != y[k]) f = 1;
					for (int k = j + 1; k < len; k++) if (x[k] != y[k]) f = 1;
					if (f) continue;
					ans++;
				}
//				cout << now1 << " " << now2 << " " << mp[now1] << "\n";
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
