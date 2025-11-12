#include <iostream>
using namespace std;
freopen("number.in", "r", stdin);
freopen("number.out", "w", stdout);

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n, a[10000];
	cin >> n;
	for (int i = 0; i <= n; i++) {
		if (a[i] == "0" || a[i] == "1" || a[i] == "2" || a[i] == "3" || a[i] == "4" || a[i] == "5" || a[i] == "6" || "7"
		        || a[i] == "8" || a[i] == "9")
			for (int j = 0; j <= i; j++) {
				if (a[j] < a[j + 1]) {
					int s = a[j + 1];
					a[j] = a[j + 1];
					a[j] = s;
				}
			}
		cout << a[i];
	}
}
rfreopen("number.in", "r", stdin);
freopen("number.out", "w", stdout);
eturn 0;
}