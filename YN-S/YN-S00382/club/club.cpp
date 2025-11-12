#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a;
ll sum = 0;
ll b1 = 0, b2 = 0, b3 = 0;
ll sum1 = 0, sum2 = 0, sum3 = 0;

struct bum {
	ll bm1;
	ll bm2;
	ll bm3;
	ll max1;
	ll maxbm;
} arr[100001];
int dp1[100001][2];
int max0 = 0;
int bmj = 0;
int df[100001];
int jz;

int fm() {
	for (int i = 0; i < a; i++) {
		if (max0 < arr[i].max1 && df[i] == 0) {
			df[jz] = 0;
			jz = i;
			bmj = arr[i].maxbm;
			max0 = arr[i].max1;
			df[i] = 1;
		}
	}
	return bmj;
}

int fen() {
	for (int i = 0; i < a; i++) {
		int bmq = fm();
		if (bmq == 1) {
			if (b1 >= a / 2) {
				int m = max(arr[jz].bm2, arr[jz].bm3);
				if (m == arr[jz].bm2) {
					b2++;
					sum2 += arr[jz].bm2;
				} else {
					b3++;
					sum3 += arr[jz].bm3;
				}
			} else {
				b1++;
				sum1 += arr[jz].bm1;
			}
		} else if (bmq == 2) {
			if (b2 >= a / 2) {
				int m = max(arr[jz].bm1, arr[jz].bm3);
				if (m == arr[jz].bm1) {
					b1++;
					sum1 += arr[jz].bm1;
				} else {
					b3++;
					sum3 += arr[jz].bm3;
				}
			} else {
				b2++;
				sum2 += arr[jz].bm2;
			}
		} else {
			if (b3 >= a / 2) {
				int m = max(arr[jz].bm1, arr[jz].bm2);
				if (m == arr[jz].bm1) {
					b1++;
					sum1 += arr[jz].bm1;
				} else {
					b2++;
					sum2 += arr[jz].bm2;
				}
			} else {
				b3++;
				sum3 += arr[jz].bm3;
			}

		}
	}
	return 0;
}

bool cmp(bum a, bum b) {
	return a.max1 > b.max1;
}

int fmax(int q) {
	arr[q].max1 = max(arr[q].bm1, arr[q].bm2);
	arr[q].max1 = max(arr[q].max1, arr[q].bm3);
	if (arr[q].max1 == arr[q].bm1)
		arr[q].maxbm = 1;
	else if (arr[q].max1 == arr[q].bm2)
		arr[q].maxbm = 2;
	else
		arr[q].maxbm = 3;
	return 0;
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 2) {
			cin >> arr[1].bm1 >> arr[1].bm2 >> arr[1].bm3;
			fmax(1);
			cin >> arr[2].bm1 >> arr[2].bm2 >> arr[2].bm3;
			fmax(2);
			if (arr[1].maxbm == arr[2].maxbm) {
				int qqq = arr[2].maxbm;
				if (arr[1].max1 > arr[2].max1) {
					if (qqq == 1) {
						cout << arr[1].max1 + max(arr[2].bm2, arr[2].bm3);
					} else if (qqq == 2) {
						cout << arr[1].max1 + max(arr[2].bm1, arr[2].bm3);
					} else {
						cout << arr[1].max1 + max(arr[2].bm1, arr[2].bm2);
					}
				}
			}
			continue;
		}
		for (int i = 0; i < a; i++) {
			df[i] = 0;
		}
		for (int j = 0; j < a; j++) {
			cin >> arr[j].bm1 >> arr[j].bm2 >> arr[j].bm3;
			fmax(j);
		}
		fen();
		cout << sum1 + sum2 + sum3 << endl;
		sum1 = 0;
		sum2 = 0;
		sum3 = 0;
	}
	return 0;
}