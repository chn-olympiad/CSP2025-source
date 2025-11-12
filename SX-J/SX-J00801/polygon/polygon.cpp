#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int n;
int a[N];
int ans = 0;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	if (n == 3) {
		if (a[2] + a[3] < a[1])
			ans = 0;
		else
			ans = 1;
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (a[i] + a[j] + a[k] > a[i] * 2)
					ans++;
			}
		}
	}
	for (int i = 1; i <= n - 3; i++) {
		for (int j = i + 1; j <= n - 2; j++) {
			for (int k = j + 1; k <= n - 1; k++) {
				for (int l = k + 1; l <= n; l++) {
					if (a[i] + a[j] + a[k] + a[l] > a[i] * 2)
						ans++;
				}
			}
		}
	}
	for (int i = 1; i <= n - 4; i++) {
		for (int j = i + 1; j <= n - 3; j++) {
			for (int k = j + 1; k <= n - 2; k++) {
				for (int l = k + 1; l <= n - 1; l++) {
					for (int m = l + 1; m <= n; m++) {
						if (a[i] + a[j] + a[k] + a[l] + a[m] > a[i] * 2)
							ans++;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n - 5; i++) {
		for (int j = i + 1; j <= n - 4; j++) {
			for (int k = j + 1; k <= n - 3; k++) {
				for (int l = k + 1; l <= n - 2; l++) {
					for (int m = l + 1; m <= n - 1; m++) {
						for (int o = m + 1; o <= n; o++) {
							if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] > a[i] * 2)
								ans++;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n - 6; i++) {
		for (int j = i + 1; j <= n - 5; j++) {
			for (int k = j + 1; k <= n - 4; k++) {
				for (int l = k + 1; l <= n - 3; l++) {
					for (int m = l + 1; m <= n - 2; m++) {
						for (int o = m + 1; o <= n - 1; o++) {
							for (int p = o + 1; p <= n; p++) {
								if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[p] > a[i] * 2)
									ans++;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n - 7; i++) {
		for (int j = i + 1; j <= n - 6; j++) {
			for (int k = j + 1; k <= n - 5; k++) {
				for (int l = k + 1; l <= n - 4; l++) {
					for (int m = l + 1; m <= n - 3; m++) {
						for (int o = m + 1; o <= n - 2; o++) {
							for (int p = o + 1; p <= n - 1; p++) {
								for (int q = p + 1; q <= n; q++) {
									if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[p] + a[q] > a[i] * 2)
										ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n - 8; i++) {
		for (int j = i + 1; j <= n - 7; j++) {
			for (int k = j + 1; k <= n - 6; k++) {
				for (int l = k + 1; l <= n - 5; l++) {
					for (int m = l + 1; m <= n - 4; m++) {
						for (int o = m + 1; o <= n - 3; o++) {
							for (int p = o + 1; p <= n - 2; p++) {
								for (int q = p + 1; q <= n - 1; q++) {
									for (int r = q + 1; r <= n; r++) {
										if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[p] + a[q] + a[r] > a[i] * 2)
											ans++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n - 9; i++) {
		for (int j = i + 1; j <= n - 8; j++) {
			for (int k = j + 1; k <= n - 7; k++) {
				for (int l = k + 1; l <= n - 6; l++) {
					for (int m = l + 1; m <= n - 5; m++) {
						for (int o = m + 1; o <= n - 4; o++) {
							for (int p = o + 1; p <= n - 3; p++) {
								for (int q = p + 1; q <= n - 2; q++) {
									for (int r = q + 1; r <= n - 1; r++) {
										for (int s = r + 1; s <= n; s++) {
											if (a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[p] + a[q] + a[r] + a[s] > a[i] * 2)
												ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ans ;
	return 0;
}