#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 8;
long long sum1[maxn][2], sum2[maxn][2];
int n, q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		int len = s1.size();
		for (int j = 0;j < len; j++){	
			long long x = (s1[j] - 'a') * 13331 + 131;
			long long y = (s2[j] - 'a') * 13331 + 131;
			sum1[j][0] = sum1[j-1][0] + x;
			sum1[j][1] = sum1[j-1][1] + y;
		}
	}
	for (int i = 1;i <= q; i++){
		string s1, s2;
		cin >> s1 >> s2;
		int ans = 0;
		int len1 = s1.size(), len2 = s2.size();
		if(len1 != len2){
			cout << 0 << endl;
			continue;
		}
		for (int j = 0;j < len1; j++){	
			long long x = (s1[j] - 'a') * 13331 + 131;
			sum2[j][0] = sum2[j-1][0] + x;
		}
		for (int j = 0;j < len2; j++){
			long long y = (s2[j] - 'a') * 13331 + 131;
			sum2[j][1] = sum2[j-1][1] + y;
		}
		for (int j = 0;j < n - len1; j++){
			int cnt1 = abs(sum1[j + len1][0] - sum1[j][0]);
			int cnt2 = abs(sum1[j + len1][1] - sum1[j][1]);
			int cnt3 = sum2[len1][0];
			int cnt4 = sum2[len1][1];
			if (abs(cnt1 - cnt2) == abs(cnt3 - cnt4)) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}