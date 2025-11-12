#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string b;
	cin >> b;
	int len_b = b.size();
	int g[1000];
	for (int i = 0; i <= len_b; i++) {
		if (b[i] >= '0' && b[i] <= '9') {
			g[i] = int(b[i]) - 48;
		}
	}
	sort(g, g + len_b);
	for (int i = len_b; i >= 0; i--) {
		if (g[i] >= 0 && g[i] < 10) {
			cout << g[i];
		}

	}
}
