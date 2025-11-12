#include <bits/stdc++.h>
using namespace std;
char q[1000010];
int z[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.getline(q + 1, 1000010);
	int n = strlen(q + 1);
	int j = 0;
	for (int i = 1; i <= n; i++) {
		if (q[i] >= '0' && q[i] <= '9') {
			j++;
			z[j] = int(q[i] - '0');
		}
	}
	sort(z + 1, z + j + 1);
	for (int i = j; i >= 1; i--) {
		cout << z[i];
	}
	return 0;
}
