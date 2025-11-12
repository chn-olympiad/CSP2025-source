#include <bits/stdc++.h>
using namespace std;
int x[100010];
char c[2000000];

int main() {
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string z;
	cin >> z;
	if (z.size() == 1) {
		cout << z;
		return 0;
	}
	for (int i = 0; i < z.size(); i++) {
		if (z[i] >= '0' && z[i] <= '9') {
			x[z[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (x[i] > 0) {
			if (x[i] >= 2) {
				for (int j = 1; j <= x[i]; j++) {
					cout << i;
				}
			} else {
				cout << i;
			}
		}
	}



	return 0;
}