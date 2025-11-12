#include <bits/stdc++.h>
using namespace std;
int n, a[5005], t[5005], cnt;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n > 2) {
		for (t[1] = 1; t[1] <= n - 2; t[1]++) {
			for (t[2] = t[1] + 1; t[2] <= n - 1; t[2]++) {
				for (t[3] = t[2] + 1; t[3] <= n; t[3]++) {
					if (max(a[t[1]], max(a[t[2]], a[t[3]])) * 2 < a[t[1]] + a[t[2]] + a[t[3]]) {
						cnt++;
					}
				}
			}
		}
	}
	if (n > 3) {
		for (t[1] = 1; t[1] <= n - 3; t[1]++) {
			for (t[2] = t[1] + 1; t[2] <= n - 2; t[2]++) {
				for (t[3] = t[2] + 1; t[3] <= n - 1; t[3]++) {
					for (t[4] = t[3] + 1; t[4] <= n; t[4]++) {
						if (max(a[t[1]], max(a[t[2]], max(a[t[4]], a[t[3]]))) * 2 < a[t[1]] + a[t[2]] + a[t[3]] + a[t[4]]) {
							cnt++;
						}
					}
				}
			}
		}
	}
	if (n > 4) {
		for (t[1] = 1; t[1] <= n - 4; t[1]++) {
			for (t[2] = t[1] + 1; t[2] <= n - 3; t[2]++) {
				for (t[3] = t[2] + 1; t[3] <= n - 2; t[3]++) {
					for (t[4] = t[3] + 1; t[4] <= n - 1; t[4]++) {
						for (t[5] = t[4] + 1; t[5] <= n; t[5]++) {
							if (max(a[t[1]], max(a[t[2]], max(a[t[4]], max(a[t[5]],
							                                  a[t[3]])))) * 2 < a[t[1]] + a[t[2]] + a[t[3]] + a[t[4]] + a[t[5]]) {
								cnt++;
							}
						}
					}
				}
			}
		}
	}
	if (n > 5) {
		for (t[1] = 1; t[1] <= n - 5; t[1]++) {
			for (t[2] = t[1] + 1; t[2] <= n - 4; t[2]++) {
				for (t[3] = t[2] + 1; t[3] <= n - 3; t[3]++) {
					for (t[4] = t[3] + 1; t[4] <= n - 2; t[4]++) {
						for (t[5] = t[4] + 1; t[5] <= n - 1; t[5]++) {
							for (t[6] = t[5] + 1; t[6] <= n; t[6]++) {
								if (max(a[t[1]], max(a[t[2]], max(a[t[4]], max(a[t[5]], max(a[t[6]],
								                                  a[t[3]]))))) * 2 < a[t[1]] + a[t[2]] + a[t[3]] + a[t[4]] + a[t[5]] + a[t[6]]) {
									cnt++;
								}
							}
						}
					}
				}
			}
		}
	}
	if (n > 6) {
		for (t[1] = 1; t[1] <= n - 6; t[1]++) {
			for (t[2] = t[1] + 1; t[2] <= n - 5; t[2]++) {
				for (t[3] = t[2] + 1; t[3] <= n - 4; t[3]++) {
					for (t[4] = t[3] + 1; t[4] <= n - 3; t[4]++) {
						for (t[5] = t[4] + 1; t[5] <= n - 2; t[5]++) {
							for (t[6] = t[5] + 1; t[6] <= n - 1; t[6]++) {
								for (t[7] = t[6] + 1; t[7] <= n; t[7]++) {
									if (max(a[t[1]], max(a[t[2]], max(a[t[4]], max(a[t[5]], max(a[t[6]], max(a[t[7]],
									                                  a[t[3]])))))) * 2 < a[t[1]] + a[t[2]] + a[t[3]] + a[t[4]] + a[t[5]] + a[t[6]] + a[t[7]]) {
										cnt++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
