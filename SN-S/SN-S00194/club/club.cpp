#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define v vector

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int t;
	cin >> t;
	
	while(t--) {
		

		
		
		int n;
		cin >> n;
		
		vector<int> a1(n), a2(n), a3(n);
			
		for(int i = 0; i < n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
		}
			
		int limit = n / 2;
			
		if (n < 1000) { //小数据暴力 	
			
			v<v<v<int>>> dp(n + 10, v<v<int>>(limit + 10, v<int>(limit + 10, 0)));
			//				cout << "r1--------" << endl;
			for(int i = 0; i < n; i++) {
				for(int s1 = 0; s1 <= min(i, limit); s1++) {
					for(int s2 = 0; s2 <= min(i - s1, limit); s2++) {
						int s3 = i - s1 - s2;
						
						if (s1 < limit && s2 <= limit && s3 <= limit && s3 >= 0) {
							dp[i + 1][s1 + 1][s2] = max(dp[i][s1][s2] + a1[i], dp[i + 1][s1 + 1][s2]);
							//cout << i + 1 << '-' << s1 + 1 << ',' << s2 << ',' << s3 << ':' << dp[i + 1][s1 + 1][s2] << "  ";
						}
						if (s1 <= limit && s2 < limit && s3 <= limit && s3 >= 0) {
							dp[i + 1][s1][s2 + 1] = max(dp[i][s1][s2] + a2[i], dp[i + 1][s1][s2 + 1]);
							//cout << i + 1 << '-' << s1 << ',' << s2 + 1 << ',' << s3 << ':' << dp[i + 1][s1][s2 + 1] << "  ";
					    }
						if (s1 <= limit && s2 <= limit && s3 < limit && s3 >= 0){
							dp[i + 1][s1][s2] = max(dp[i][s1][s2] + a3[i], dp[i + 1][s1][s2]);
							//cout << i + 1 << '-' << s1 << ',' << s2 << ',' << s3 << ':' << dp[i + 1][s1][s2] << endl;
						}
							
					}
				}
			}
			
			int maxn = 0;
			for(auto i : dp[n]) {
				for(auto j : i) {
				maxn = max(maxn, j);
				}
			}
			
			cout << maxn << endl;
			//						cout << "r1--------" << endl;
		}
		else {
			bool ifa2a3is0 = true;
			bool ifa3is0 = true;
			for(int i = 0; i < n; i++) {
				if(a2[i] != 0 or a3[i] != 0) ifa2a3is0 = false;
				if (a3[i] != 0) ifa3is0 = false;
			}
			if (ifa2a3is0) { //特殊性质 A骗分 
				sort(a1.begin(), a1.end(), greater<int>());
				int ans = 0;
				for(int i = 0; i < n / 2; i++) {
					ans += a1[i];
				}
				cout << ans;
			}
			else if (ifa3is0) { //特殊性质 B骗分 
				vector<pair<int, int>> c(n);
				for(int i = 0; i < n; i++) {
					c[i].first = a1[i] - a2[i];
					c[i].second = i;
				}
		
				sort(c.begin(), c.end(), [](pair<int, int> a, pair<int, int> b) {
					return a.first > b.first;
				});
				
				int ans = 0;
				for(int i = 0; i < n / 2; i++) {
					ans += a1[c[i].second];
				}
				for(int i = n / 2; i < n; i++) {
					ans += a2[c[i].second];
				}
				cout << ans << endl;
			} else { //骗不到了呜呜，乱搞 也许能骗到性质C? 
				v<v<int>> dp(n + 10, vector<int> (4, 0));
		//				cout << "r1--------" << endl;
				for(int i = 0; i < n; i++) {
					int s1 = dp[i][1], s2 = dp[i][2], s3 = dp[i][3];
							
						if (s1 < limit && s2 <= limit && s3 <= limit && s3 >= 0) {
							dp[i + 1][0] = max(dp[i][0] + a1[i], dp[i + 1][0]);
							dp[i + 1][1] ++;
							//cout << i + 1 << '-' << s1 + 1 << ',' << s2 << ',' << s3 << ':' << dp[i + 1][s1 + 1][s2] << "  ";
						}
						if (s1 <= limit && s2 < limit && s3 <= limit && s3 >= 0) {
							dp[i + 1][0] = max(dp[i][0] + a2[i], dp[i + 1][0]);
							dp[i + 1][2] ++;
							//cout << i + 1 << '-' << s1 << ',' << s2 + 1 << ',' << s3 << ':' << dp[i + 1][s1][s2 + 1] << "  ";
						}
						if (s1 <= limit && s2 <= limit && s3 < limit && s3 >= 0){
							dp[i + 1][0] = max(dp[i][0] + a3[i], dp[i + 1][0]);
							dp[i + 1][3] ++;
							//cout << i + 1 << '-' << s1 << ',' << s2 << ',' << s3 << ':' << dp[i + 1][s1][s2] << endl;
						}
		
				}
				cout << dp[n][0] << endl;
			}
		}
	}		
	
	
	return 0;
}
