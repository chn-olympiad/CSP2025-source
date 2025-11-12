#include <iostream>
using namespace std;
int s[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int M = 0, N = 0;
	cin >> N >> M;
	int num = N * M;
	int num1 = 0;
	int a[105];
	int cnt = 1;
	for (int i = 1; i <= num; i++) {
		cin >> a[i];
	}
	num1 = a[1];
	for (int i = 1; i <= num ; i++) {
		for (int j = i; j <= num  ; j++) {
			if (a[j] >= a[i]) {
				swap(a[j], a[i]);
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= N; j++) {
				s[i][j] = a[cnt];
				cnt++;
			}
		} else {
			for (int j = N; j >= 1; j--) {
				s[i][j] = a[cnt];
				cnt++;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if ( s[j][i] == num1 ) {
				cout << j << " " << i;
			}

		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
