#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20;
long long t, n, acl[N], bcl[N], ccl[N], sm[10], an = 0, bn = 0, cn = 0;

struct node {
	int clu, val, can;
};
node chos[N], chan[N];

void cmp(int x, int y, int z, int i) {
	if (x > y) {
		if (y > z) {
			chos[i].clu = 1;
			chan[i].clu = 2;
		} else if (y == z) {
			chos[i].clu = 1;
			if (bn >= cn) {
				chan[i].clu = 3;
			} else {
				chan[i].clu = 2;
			}
		} else {
			if (x > z) {
				chos[i].clu = 1;
				chan[i].clu = 3;
			} else if (x == z) {
				if (an >= cn) {
					chos[i].clu = 3;
					chan[i].clu = 1;
				} else {
					chos[i].clu = 1;
					chan[i].clu = 3;
				}
			} else {
				chos[i].clu = 3;
				chan[i].clu = 1;
			}
		}
	} else if (x == y) {
		if (y > z) {
			if (an >= bn) {
				chos[i].clu = 2;
				chan[i].clu = 1;
			} else {
				chos[i].clu = 1;
				chan[i].clu = 2;
			}
		} else if (y == z) {
			if (an >= bn) {
				if (bn >= cn) {
					chos[i].clu = 3;
					chan[i].clu = 2;
				} else {
					chos[i].clu = 2;
					chan[i].clu = 3;
				}
			} else {
				if (an >= cn) {
					chos[i].clu = 3;
					chan[i].clu = 1;
				} else {
					chos[i].clu = 1;
					chan[i].clu = 3;
				}
			}
		} else {
			chos[i].clu = 3;
			if (an >= bn) {
				chan[i].clu = 2;
			} else {
				chan[i].clu = 1;
			}
		}
	} else {
		if (x > z) {
			chos[i].clu = 2;
			chan[i].clu = 1;
		} else if (x == z) {
			chos[i].clu = 2;
			if (an >= cn) {
				chan[i].clu = 3;
			} else {
				chan[i].clu = 1;
			}
		} else {
			if (y > z) {
				chos[i].clu = 2;
				chan[i].clu = 3;
			} else if (y == z) {
				if (bn >= cn) {
					chos[i].clu = 3;
					chan[i].clu = 2;
				} else {
					chos[i].clu = 2;
					chan[i].clu = 3;
				}
			} else {
				chos[i].clu = 3;
				chan[i].clu = 2;
			}
		}
	}
}

bool cmps(node a, node b) {
	if (a.can == b.can) {
		return a.val < b.val;
	} else {
		return a.can < b.can;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int q = 1; q <= t; q++) {
		memset(acl, 0, sizeof(acl));
		memset(bcl, 0, sizeof(bcl));
		memset(ccl, 0, sizeof(ccl));
		an = 0;
		bn = 0;
		cn = 0;
		n = 0;
		node df;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			chan[i] = df;
			chos[i] = df;
		}
		for (int i = 1; i <= n; i++) {
			cin >> acl[i] >> bcl[i] >> ccl[i];
			cmp(acl[i], bcl[i], ccl[i], i);
			if (chos[i].clu == 1) {
				an++;
				chos[i].val = acl[i];
			} else if (chos[i].clu == 2) {
				bn++;
				chos[i].val = bcl[i];
			} else {
				cn++;
				chos[i].val = ccl[i];
			}
			if (chan[i].clu == 1) {
				chan[i].val = acl[i];
			} else if (chan[i].clu == 2) {
				chan[i].val = bcl[i];
			} else {
				chan[i].val = ccl[i];
			}
			chos[i].can = chos[i].val - chan[i].val;
		}
		for (int i = 1; i <= n; i++) {
			sm[q] += chos[i].val;
		}
		if (an < n / 2 && bn < n / 2 && cn < n / 2) {
			continue;
		} else {
			node bx[N];
			int s = 0;
			if (an > n / 2) {
				int k = an - n / 2;
				for (int i = 1; i <= n; i++) {
					if (chos[i].clu == 1) {
						s++;
						node tmp = chos[i];
						bx[s] = tmp;
					}
				}
				sort(bx + 1, bx + s + 1, cmps);
				for (int i = 1; i <= k; i++) {
					sm[q] = sm[q] - bx[i].can;
				}
			} else if (bn > n / 2) {
				int k = bn - n / 2;
				for (int i = 1; i <= n; i++) {
					if (chos[i].clu == 2) {
						s++;
						node tmp = chos[i];
						bx[s] = tmp;
					}
				}
				sort(bx + 1, bx + s + 1, cmps);
				for (int i = 1; i <= k; i++) {
					sm[q] = sm[q] - bx[i].can;
				}
			}
			if (cn > n / 2) {
				int k = cn - n / 2;
				for (int i = 1; i <= n; i++) {
					if (chos[i].clu == 3) {
						s++;
						node tmp = chos[i];
						bx[s] = tmp;
					}
				}
				sort(bx + 1, bx + s + 1, cmps);
				for (int i = 1; i <= k; i++) {
					sm[q] = sm[q] - bx[i].can;
				}
			}
		}
	}
	for (int i = 1; i <= t; i++) {
		cout << sm[i] << endl;
	}
	return 0;
}