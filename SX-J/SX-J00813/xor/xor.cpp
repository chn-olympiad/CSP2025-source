#include <bits/stdc++.h>
using namespace std;
const int M = 1048577;
int w[M];
int n, k;
int as = n;
//bool t[M], p[M];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	as = n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	int  lp = 1;
	for (int i = 1; i <= n; i++) {
		if (w[i] != k ) {
			bool uk = 0;
			int sg = 0;
			for (int j = i - 1; j >= lp; j--) {
				sg = (sg ^w[j]);
				if ((sg ^ w[i]) == k) {
					uk = 1;
					break;
				}
			}
			if (!uk)
				as--;
			else
				lp = i + 1;

		} else {
			lp = i + 1;
		}
	}
	cout << as << endl;
}
