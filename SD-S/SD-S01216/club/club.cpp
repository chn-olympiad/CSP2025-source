#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5;
const int DPMAXN = 200;

int a[MAXN][3];
struct Person {
	int x[3];
} persons[MAXN + 5];

// S1
long long dp[DPMAXN + 5][DPMAXN + 5][DPMAXN + 5];
int chosen[DPMAXN + 5];
// SubtaskB
int bucket[3];

int main() {
//	freopen(R"(C:\Users\Administrator\Desktop\csps\down\club\club4.in)", "r", stdin);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		bool subtaskB = true;
		for(int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			persons[i].x[0] = a[i][0];
			persons[i].x[1] = a[i][1];
			persons[i].x[2] = a[i][2];
			if(a[i][2] != 0)
				subtaskB = false;
		}
		if(n <= 200) {
			for(int i = 1; i <= n; i++) {
				for(int x = 0; x <= min(i, n / 2); x++) {
					for(int y = 0; x + y <= min(i, n) && y <= n / 2; y++) {
						dp[i][x][y] = 0; 
						if(i - x - y > n / 2)
							continue;
						if(i - x - y < 0)
							continue;
						if(x > 0) {
							if(dp[i - 1][x - 1][y] + a[i][0] > dp[i][x][y])
								chosen[i] = 0;
							dp[i][x][y] = max(dp[i][x][y], dp[i - 1][x - 1][y] + a[i][0]);
						}
						if(y > 0) {
							if(dp[i - 1][x][y - 1] + a[i][1] > dp[i][x][y])
								chosen[i] = 1;
							dp[i][x][y] = max(dp[i][x][y], dp[i - 1][x][y - 1] + a[i][1]);
						}
						if(i - x - y > 0) {
							if(dp[i - 1][x][y] + a[i][2] > dp[i][x][y])
								chosen[i] = 2;
							dp[i][x][y] = max(dp[i][x][y], dp[i - 1][x][y] + a[i][2]);
						}
					}
				}
			}
			long long ans = 0;
			for(int x = 0; x <= n / 2; x++) {
				for(int y = 0; y <= n / 2 && x + y <= n; y++) {
//					cout << x << ' ' << y << ' ' << dp[n][x][y] << endl;
					ans = max(ans, dp[n][x][y]);
				}
			}
			cout << ans << endl;
		} else if(subtaskB) {
			sort(persons + 1, persons + n + 1, [](Person a, Person b) {
				return max(a.x[0] - a.x[1], a.x[1] - a.x[0]) > max(b.x[0] - b.x[1], b.x[1] - b.x[0]);
			});
			long long ans = 0;
			bucket[0] = bucket[1] = 0;
			for(int i = 1; i <= n; i++) {
				if(bucket[0] >= n / 2) {
					ans += persons[i].x[1];
					bucket[1]++;
					continue;
				}
				if(bucket[1] >= n / 2) {
					ans += persons[i].x[0];
					bucket[0]++;
					continue;
				}
				if(persons[i].x[0] > persons[i].x[1]) {
					ans += persons[i].x[0];
					bucket[0]++;
				} else {
					ans += persons[i].x[1];
					bucket[1]++;
				}
			}
			cout << ans << endl;
		} else {
			long long ans = 0;
			for(int i = 1; i <= n; i++) {
				Person &p = persons[i];
				ans += max(max(p.x[0], p.x[1]), p.x[2]);
			}
			cout << ans << endl;
		}
	}
}
