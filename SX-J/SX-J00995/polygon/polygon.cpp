#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
long long n, s = 0;
int a[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}
	if (n == 3) {
		if (a[1] + a[2] + a[3] > 2 * max(max(a[1], a[2]), max(a[2], a[3]))) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else if (n < 3) {
		cout << 0;
	} else {
		if (n >= 3) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						if (a[i] + a[j] + a[k] > 2 * max(max(a[i], a[j]), max(a[j], a[k]))) {
							s++;
							s = s % 998244353;
						}
					}
				}
			}
		}
		if (n >= 4) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							if (a[i] + a[j] + a[k] + a[l] > 2 * max(a[l], max(max(a[i], a[j]), max(a[j], a[k])))) {
								s++;
								s = s % 998244353;
							}
						}
					}
				}
			}
		}
		if (n >= 5) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								if (a[i] + a[j] + a[k] + a[l] + a[m] > 2 * max(max(a[l], a[m]), max(max(a[i], a[j]), max(a[j], a[k])))) {
									s++;
									s = s % 998244353;
								}
							}
						}
					}
				}
			}
		}
		if (n >= 6) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int b = m + 1; b <= n; b++) {
									if (a[i] + a[j] + a[k] + a[l] + a[m] + a[b] > 2 * max(max(max(a[l], a[m]), a[b]), max(max(a[i], a[j]), max(a[j],
									        a[k])))) {
										s++;
										s = s % 998244353;
									}
								}
							}
						}
					}
				}
			}
		}
		if (n >= 7) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int b = m + 1; b <= n; b++) {
									for (int c = b + 1; c <= n; c++) {
										if (a[i] + a[j] + a[k] + a[l] + a[m] + a[b] + a[c] > 2 * max(max(max(a[l], a[m]), max(a[b], a[c])), max(max(a[i], a[j]),
										        max(a[j], a[k])))) {
											s++;
											s = s % 998244353;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (n >= 8) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int b = m + 1; b <= n; b++) {
									for (int c = b + 1; c <= n; c++) {
										for (int d = c + 1; d <= n; d++) {
											if (a[i] + a[j] + a[k] + a[l] + a[m] + a[b] + a[c] + a[d] > 2 * max(a[d], max(max(max(a[l], a[m]), max(a[b], a[c])),
											        max(max(a[i], a[j]), max(a[j], a[k]))))) {
												s++;
												s = s % 998244353;
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
		if (n >= 9) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int b = m + 1; b <= n; b++) {
									for (int c = b + 1; c <= n; c++) {
										for (int d = c + 1; d <= n; d++) {
											for (int e = d + 1; e <= n; e++) {
												if (a[i] + a[j] + a[k] + a[l] + a[m] + a[b] + a[c] + a[d] + a[e] > 2 * max(max(a[e], a[d]), max(max(max(a[l], a[m]),
												        max(a[b], a[c])), max(max(a[i], a[j]), max(a[j], a[k]))))) {
													s++;
													s = s % 998244353;
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
		}
		if (n >= 10) {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						for (int l = k + 1; l <= n; l++) {
							for (int m = l + 1; m <= n; m++) {
								for (int b = m + 1; b <= n; b++) {
									for (int c = b + 1; c <= n; c++) {
										for (int d = c + 1; d <= n; d++) {
											for (int e = d + 1; e <= n; e++) {
												for (int f = e + 1; f <= n; f++) {
													if (a[i] + a[j] + a[k] + a[l] + a[m] + a[b] + a[c] + a[d] + a[e] + a[f] > 2 * max(max(max(a[e], a[f]), a[d]),
													        max(max(max(a[l], a[m]), max(a[b], a[c])), max(max(a[i], a[j]), max(a[j], a[k]))))) {
														s++;
														s = s % 998244353;
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
			}

		}
		cout << s;

	}
	return 0;
}
