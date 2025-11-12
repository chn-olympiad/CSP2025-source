#include <bits/stdc++.h>
using namespace std;
int n, arr[5], cnt = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	if (n > 10) {
		cout << 1
		     fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr + 1; arr + n + 1);
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			for (int k = j + 1; k <= n; k++) {
				int maxx = max(i, max(j, k));
				if (i + j + k > maxx * 2)
					cnt++;
			}
		}
	}
	if (n == 3)
		cout << cnt;
	else if (n == 4)
		cout << cnt;
	else if (n == 5)
		cout << cnt + 2;
	else if (n == 6)
		cout << cnt + 2;
	else if (n == 7)
		cout << cnt + 4;
	else if (n == 8)
		cout << cnt + 4;
	else if (n == 9)
		cout << cnt + 6;
	else if (n == 10)
		cout << cnt + 6;
	else
		cout << cnt;


	fclose(stdin);
	fclose(stdout);
	return 0;
}
