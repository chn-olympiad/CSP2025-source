#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 10;
ll T, n, res = 0;
struct Node{ll va[3];}arr[MAXN];

bool cmp(Node A, Node B) {return A.va[0] > B.va[0];}
void solve2() {
	sort(arr, arr + n, cmp);
	for(int i = 0; i < n / 2; i++)
		res += arr[i].va[0];
	cout << res << "\n";
}

ll dp[105][105][105];
void solve1() {
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++)
		for(int j = n / 2; j >= 0; j--)
			for(int k = n / 2; k >= 0; k--)
				for(int l = n / 2; l >= 0; l--) {
					if(j != 0) dp[j][k][l] = max(dp[j][k][l], dp[j - 1][k][l] + arr[i].va[0]);
					if(k != 0) dp[j][k][l] = max(dp[j][k][l], dp[j][k - 1][l] + arr[i].va[1]);
					if(l != 0) dp[j][k][l] = max(dp[j][k][l], dp[j][k][l - 1] + arr[i].va[2]);
				}
	cout << dp[n / 2][n / 2][n / 2] << "\n";
}

void solve3() {
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++)
		for(int j = n / 2; j >= 0; j--)
			for(int k = n / 2; k >= 0; k--) {
				if(j != 0) dp[j][k][0] = max(dp[j][k][0], dp[j - 1][k][0] + arr[i].va[0]);
				if(k != 0) dp[j][k][0] = max(dp[j][k][0], dp[j][k - 1][0] + arr[i].va[1]);
			}
	cout << dp[n / 2][n / 2][0] << "\n";
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		res = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < 3; j++)
				cin >> arr[i].va[j];
		if(n <= 32) solve1();
		else {
			// A
			bool Flag = false;
			for(int i = 0; i < n; i++)
				if(arr[i].va[1] != 0 || arr[i].va[2] != 0) {
					Flag = true;
					break;
				}
			if(!Flag) solve2();
			else { // B
				solve3();
			}
		}
	}
	return 0;
}
