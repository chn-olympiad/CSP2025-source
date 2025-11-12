#include<bits/stdc++.h>

using namespace std;

const int N = 5e6 + 10;

int n, q;
string s1[N], s2[N];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
		s1[i] = ' ' + s1[i], s2[i] = ' ' + s2[i];
	}
	while(q--){
		int ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		t1 = ' ' + t1;
		t2 = ' ' + t2;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= t1.size() - s1[i].size() + 1; j++){
				if(t1[j] == s1[i][1]){
					bool ok = 1;
					for(int k = 1; k <= s1[i].size() - 1; k++){
						if(t1[j + k - 1] != s1[i][k]){
							ok = 0;
							break;
						}
					}
					if(ok == 0) continue;
					string t3 = t1;
					for(int k = 1; k <= s1[i].size() - 1; k++){
						t3[j + k - 1] = s2[i][k];
					}
					if(t3 == t2){
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
