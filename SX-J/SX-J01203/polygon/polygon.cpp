#include <bits/stdc++.h>
using namespace std;
int n, a[50005], h, zd, ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				h = a[i] + a[j] + a[k];
				zd = max(max(a[i], a[j]), a[k]);
				if (h > zd * 2)
					ans++;
				else
					break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					h = a[i] + a[j] + a[k] + a[l];
					zd = max(max(max(a[i], a[j]), a[k]), a[l]);
					if (h > zd * 2)
						ans++;
					else
						break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int o = l + 1; o <= n; o++) {
						h = a[i] + a[j] + a[k] + a[l] + a[o];
						zd = max(max(max(max(a[i], a[j]), a[k]), a[l]), a[o]);
						if (h > zd * 2)
							ans++;
						else
							break;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int o = l + 1; o <= n; o++) {
						for (int p = o + 1; p <= n; p++) {
							h = a[i] + a[j] + a[k] + a[l] + a[o] + a[p];
							zd = max(max(max(max(max(a[i], a[j]), a[k]), a[l]), a[o]), a[p]);
							if (h > zd * 2)
								ans++;
							else
								break;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int o = l + 1; o <= n; o++) {
						for (int p = o + 1; p <= n; p++) {
							for (int u = p + 1; u <= n; u++) {
								h = a[i] + a[j] + a[k] + a[l] + a[o] + a[p] + a[u];
								zd = max(max(max(max(max(max(a[i], a[j]), a[k]), a[l]), a[o]), a[p]), a[u]);
								if (h > zd * 2)
									ans++;
								else
									break;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int o = l + 1; o <= n; o++) {
						for (int p = o + 1; p <= n; p++) {
							for (int u = p + 1; u <= n; u++) {
								for (int q = u + 1; q <= n; q++) {
									h = a[i] + a[j] + a[k] + a[l] + a[o] + a[p] + a[u] + a[q];
									zd = max(max(max(max(max(max(max(a[i], a[j]), a[k]), a[l]), a[o]), a[p]), a[u]), a[q]);
									if (h > zd * 2)
										ans++;
									else
										break;
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int l = k + 1; l <= n; l++) {
					for (int o = l + 1; o <= n; o++) {
						for (int p = o + 1; p <= n; p++) {
							for (int u = p + 1; u <= n; u++) {
								for (int q = u + 1; q <= n; q++) {
									for (int w = q + 1; w <= n; w++) {
										h = a[i] + a[j] + a[k] + a[l] + a[o] + a[p] + a[u] + a[q] + a[w];
										zd = max(max(max(max(max(max(max(max(a[i], a[j]), a[k]), a[l]), a[o]), a[p]), a[u]), a[q]), a[w]);
										if (h > zd * 2)
											ans++;
										else
											break;
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
		h = 0, zd = 0;
		for (int i = 1; i <= n; i++) {
			h += a[i];
			if (a[i] > zd)
				zd = a[i];
		}
		if (h > zd * 2)
			ans++;
	}
	cout << ans % 998244353;
	return 0;
}
