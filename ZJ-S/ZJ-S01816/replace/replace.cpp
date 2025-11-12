#include<bits/stdc++.h>
using namespace std;
#define CSP
int n, q;
string s1[200010], s2[100010];
string t1[200010], t2[200010];
int main(){
#ifdef CSP
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#endif
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++){
		cin >> t1[i] >> t2[i];
		if(t1[i].length() != t2[i].length())cout << 0 << endl;
		else{
			int sum = 0;
			for(int j = 1; j <= n; j++){
				int x = t2[i].find(s2[j]);
				if(x == -1)continue;
				int l = s2[j].length();
				string s = t2[i];
				for (int k = x; k < x + l; k++){
					s[k] = s1[j][k - x];
				}
//				cout << x << endl;
				if(s == t1[i])sum++;
			}
			cout << sum << endl;
		}
	}
	return 0;
}
