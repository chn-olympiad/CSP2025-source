#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXN 20
using namespace std;
int arr[MAXN*MAXN];
int cmp(int &a, int &b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int n, m, len, x, num, lie = 1, hang = 1, d = 1;
	cin >> n >> m;
	len = n * m;
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	} 
	x = arr[0];
	sort(arr, arr + len, cmp);
	for (int i = 0; i < len; i++) {
		if (arr[i] == x) {
			cout << lie << " " << hang;
			break;
		}
		if (1 <= hang + d && hang + d <= n) {
			hang += d;
		} else {
			lie++;
			d = -d;
		}
	}
	return 0;
}

