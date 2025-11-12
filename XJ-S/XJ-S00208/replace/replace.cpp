#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2e5 + 5;
int n, q; 
struct node{
	string be, re, af;
	int l;
}a[MAXN];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		int cnt1 = -1, cnt2 = -1;
		for (int j = 0; j < s1.length(); j++) if (s1[j] != s2[j] && cnt1 == -1) cnt1 = j;
		for (int j = s1.length() - 1; j >= 0; j--) if (s1[j] != s2[j] && cnt2 == -1) cnt2 = j;
		for (int j = 0; j < s1.length(); j++){
			if (j < cnt1) a[i].be += s1[j];
			if (j >= cnt1 && j <= cnt2) a[i].re += s1[j] , a[i].re += s2[j];
			if (j > cnt2) a[i].af += s1[j];
		}
		a[i].l = s1.length();
	}
//	for (int i = 1; i <= n; i++){
//		cout << a[i].be << " " << a[i].re << " " << a[i].af << endl;
//	}
	while (q--){
		string s1, s2;
		cin >> s1 >> s2;
		if (s1.length() != s2.length()){
			cout << 0 << endl;
			continue;
		}
		int cnt1 = -1, cnt2 = -1;
		for (int i = 0; i < s1.length(); i++) if (s1[i] != s2[i] && cnt1 == -1) cnt1 = i;
		for (int i = s1.length() - 1; i >= 0; i--) if (s1[i] != s2[i] && cnt2 == -1) cnt2 = i;
		int ans = 0;
		for (int i = 1; i <= n; i++){
			if (cnt2 - cnt1 + 1 != a[i].re.length() / 2) continue;
			if (cnt1 < a[i].be.length()) continue;
			if (s1.length() - cnt2 - 1 < a[i].af.length()) continue;
			bool flag = 1;
			for (int j = a[i].be.length() - 1, k = cnt1 - 1; j >= 0; j--, k--){
				if (a[i].be[j] != s1[k]){
					flag = 0;
					break;
				}
			}
			if (!flag) continue;
			for (int j = 0, k = cnt1; j < a[i].re.length(); ){
				if (a[i].re[j] != s1[k]){
					flag = 0;
					break;
				}
				j++;
				if (a[i].re[j] != s2[k]){
					flag = 0;
					break;
				}
				j++, k++;
			}
			if (!flag) continue;
			for (int j = 0, k = cnt2 + 1; j < a[i].af.length(); j++, k++){
				if (a[i].af[j] != s1[k]){
					flag = 0;
					break;
				}
			}
			if (flag) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

