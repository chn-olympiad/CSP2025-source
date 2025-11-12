#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int scores[110];
	int arr[20][20];
	int cnt = 0;
	int rScore;
	for(int i = 0; i < n * m; i++) {
		cin >> scores[i];
	}
	rScore = scores[0];
	sort(scores, scores + n * m, greater<int>());
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(i % 2) {
				arr[j][i] = scores[cnt];
			} else {
				arr[n - j + 1][i] = scores[cnt];
			}
			cnt++;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(arr[i][j] == rScore) {
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
}