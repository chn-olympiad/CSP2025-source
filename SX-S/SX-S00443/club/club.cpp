#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;

int a[5][N];
int aa[N], bb[N], cc[N];

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("club5.in", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
//		cout << "*&&&&";
		if (n == 2) {

			for (int i = 1; i <= n; i++)
				cin >> a[1][i] >> a[2][i] >> a[3][i];
			int num = 0;
			num = max(num, a[1][1] + a[2][2]);
			num = max(num, a[1][1] + a[3][2]);
			num = max(num, a[2][1] + a[1][2]);
			num = max(num, a[2][1] + a[3][2]);
			num = max(num, a[3][1] + a[1][2]);
			num = max(num, a[3][1] + a[2][2]);
			cout << num << endl;
		} else if (n == 4) {

//			cout << "^^^^^";
			for (int i = 1; i  <= n; i++)
				cin >> a[1][i] >> a[2][i] >> a[3][i];
//			cout << "^^^^^";
			int num = 0;
//			cout << "^^^^^";
			num = max(num, a[1][1] + a[1][2] + a[2][3] + a[3][4]);
			num = max(num, a[1][1] + a[1][2] + a[2][4] + a[3][3]);
			num = max(num, a[1][1] + a[1][3] + a[2][2] + a[3][4]);
			num = max(num, a[1][1] + a[1][3] + a[2][4] + a[3][2]);
			num = max(num, a[1][1] + a[1][4] + a[2][2] + a[3][3]);
			num = max(num, a[1][1] + a[1][4] + a[2][3] + a[3][2]);
			num = max(num, a[1][2] + a[1][3] + a[2][1] + a[3][4]);
			num = max(num, a[1][2] + a[1][3] + a[2][4] + a[3][1]);
			num = max(num, a[1][2] + a[1][4] + a[2][2] + a[3][3]);
			num = max(num, a[1][2] + a[1][4] + a[2][3] + a[3][2]);
			num = max(num, a[1][3] + a[1][4] + a[2][1] + a[3][2]);
			num = max(num, a[1][3] + a[1][4] + a[2][2] + a[3][1]);
			num = max(num, a[2][1] + a[2][2] + a[1][3] + a[3][4]);
			num = max(num, a[2][1] + a[2][2] + a[1][4] + a[3][3]);
			num = max(num, a[2][1] + a[2][3] + a[1][2] + a[3][4]);
			num = max(num, a[2][1] + a[2][3] + a[1][4] + a[3][2]);
			num = max(num, a[2][1] + a[2][4] + a[1][2] + a[3][3]);
			num = max(num, a[2][1] + a[2][4] + a[1][3] + a[3][2]);
			num = max(num, a[2][2] + a[2][3] + a[1][1] + a[3][4]);
			num = max(num, a[2][2] + a[2][3] + a[1][4] + a[3][1]);
			num = max(num, a[2][2] + a[2][4] + a[1][2] + a[3][3]);
			num = max(num, a[2][2] + a[2][4] + a[1][3] + a[3][2]);
			num = max(num, a[2][3] + a[2][4] + a[1][1] + a[3][2]);
			num = max(num, a[2][3] + a[2][4] + a[1][2] + a[3][1]);
			num = max(num, a[3][1] + a[3][2] + a[1][3] + a[2][4]);
			num = max(num, a[3][1] + a[3][2] + a[1][4] + a[2][3]);
			num = max(num, a[3][1] + a[3][3] + a[1][2] + a[2][4]);
			num = max(num, a[3][1] + a[3][3] + a[1][4] + a[2][2]);
			num = max(num, a[3][1] + a[3][4] + a[1][2] + a[2][3]);
			num = max(num, a[3][1] + a[3][4] + a[1][3] + a[2][2]);
			num = max(num, a[3][2] + a[3][3] + a[1][1] + a[2][4]);
			num = max(num, a[3][2] + a[3][3] + a[1][4] + a[2][1]);
			num = max(num, a[3][2] + a[3][4] + a[1][2] + a[2][3]);
			num = max(num, a[3][2] + a[3][4] + a[1][3] + a[2][2]);
			num = max(num, a[3][3] + a[3][4] + a[1][1] + a[2][2]);
			num = max(num, a[3][3] + a[3][4] + a[1][2] + a[2][1]);
			cout << num << endl;
		} else {
			int sumb = 0, sumc = 0;
			for (int i = 1; i <= n; i++) {
				cin >> aa[i] >> bb[i] >> cc[i];
				sumb += bb[i];
				sumc += cc[i];
			}
			if (sumb == 0) {
				sort(aa + 1, aa + n + 1);
				int num = 0;
				for (int i = n; i >= n / 2; i--)
					num += aa[i];
				cout << num << endl;
			} else {
//				for (int i = 1; i <= n; i++)
//					cin >> aa[i] >> bb[i] >> cc[i];
//				cout << "****";
				sort(aa + 1, aa + n + 1, cmp);
				sort(bb + 1, bb + n + 1, cmp);
				sort(cc + 1, cc + n + 1, cmp);
				int num = 0;
				int pos1 = 1, pos2 = 1, pos3 = 1;
				for (int i = 1; i <= n; i++) {
					bool f = 1;
					if (aa[pos1] >= bb[pos2] && aa[pos1] >= cc[pos3] && f) {
						if (pos1 > n / 2) {
							if (bb[pos2] >= cc[pos3] && pos2 <= n / 2) {
								num += bb[pos2];
								pos2++;
								f = 0;
//						cout << " 011 " << " ";
							} else {
								num += cc[pos3];
								pos3++;
								f = 0;
//						cout << " 012 " << " ";
							}
						} else {
							num += aa[pos1];
							pos1++;
							f = 0;
//					cout << " 013 " << " ";
						}

					}
					if (bb[pos2] >= aa[pos1] && bb[pos2] >= cc[pos3] && f) {
						if (pos2 > n / 2) {
							if (aa[pos1] >= cc[pos3] && pos1 <= n / 2) {
								num += aa[pos1];
								pos1++;
								f = 0;
//						cout << " 021 " << " ";
							} else {
								num += cc[pos3];
								pos3++;
								f = 0;
//						cout << " 022 " << " ";
							}
						} else {
							num += bb[pos2];
							pos2++;
							f = 0;
//					cout << " 023 " << " ";
						}

					}
					if (cc[pos3] >= bb[pos2] && cc[pos3] >= aa[pos1] && f) {
						if (pos3 > n / 2) {
							if (bb[pos2] >= aa[pos1] && pos2 <= n / 2) {
								num += bb[pos2];
								pos2++;
								f = 0;
//						cout << " 031 " << " ";
							} else {
								num += aa[pos1];
								pos1++;
								f = 0;
//						cout << " 032 " << " ";
							}
						} else {
							num += cc[pos3];
							pos3++;
							f = 0;
//					cout << " 033 " << " ";
						}

					}
//			cout << num << " ";
				}
				cout << num << endl;
			}
		}

	}
	return 0;
}
