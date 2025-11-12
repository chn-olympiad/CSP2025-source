#include<bits/stdc++.h>
using namespace std;
int n, q;
string s[200005][3], t1, t2;
int main(){
	std::ios::sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> s[i][1] >> s[i][2];
	}
	while (q--){
		cin >> t1 >> t2;
		int af1, ab1, af2, ab2, l1, l;
		l = t1.length();
		for (int i = 0; i < l; i++){
			if (t1[i] == 'b'){
				af1 = i;
				ab1 = l-i-1;
			}
			if (t2[i] == 'b'){
				af2 = i;
				ab2 = l-i-1;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			l1 = s[i][1].length();
			int aff1, aff2, abb1, abb2;
			for (int j = 0; j < l1; j++){
				if (s[i][1][j] == 'b'){
					aff1 = j;
					abb1 = l1-j-1;
				}
				if (s[i][2][j] == 'b'){
					aff2 = j;
					abb2 = l1-j-1;
				}
			}
			if (aff1-aff2==af1-af2 && aff1<=af1 && aff2<=af2 && abb1<=ab1 && abb2<=ab2){
				ans++;
			}
		}
		cout << ans << endl;
	}
    return 0;
}