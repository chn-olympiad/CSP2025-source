#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 20;
int n, m, cnt = 1;
int seat[N][N];
int score[N * N], sc;
bool _front = 1;

bool cmp(int f1, int f2) {
    return f1 > f2;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> score[i];

    sc = score[1];
    sort(score + 1, score + n * m + 1, cmp);
    
    for (int i = 1; i <= n; i++) {
		if (_front) {
			for (int j = 1; j <= m; j++) {
				seat[i][j] = score[cnt++];
				if (seat[i][j] == sc) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			for (int j = m; j >= 1; j--) {
				seat[i][j] = score[cnt++];
				if (seat[i][j] == sc) {
					cout << i << " " << j;
					return 0;
				} 
			}
		}
		_front = !(_front);
	}
    return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
