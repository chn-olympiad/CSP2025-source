#include <bits/stdc++.h>
using namespace std;

int n, q, lens[200010], s1b[200010], s2b[200010];
string s1[200010], s2[200010], t1, t2;
vector<int> d[10000010];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
		lens[i] = s1[i].length();
		for(int j = 0; j < lens[i]; j++){
			if(s1[i][j] == 'b'){
				s1b[i] = j;
				break;
			}
		}
		for(int j = 0; j < lens[i]; j++){
			if(s2[i][j] == 'b'){
				s2b[i] = j;
				break;
			}
		}
		d[s2b[i]-s1b[i]+5000005].push_back(i);
	}
	while(q--){
		cin >> t1 >> t2;
		int lent = t1.length(), t1b = 0, t2b = 0, ans = 0;
		for(int j = 0; j < lent; j++){
			if(t1[j] == 'b'){
				t1b = j;
				break;
			}
		}
		for(int j = 0; j < lent; j++){
			if(t2[j] == 'b'){
				t2b = j;
				break;
			}
		}
		for(int x : d[t2b-t1b+5000005]){
			if(t1b+(lens[x]-s1b[x]) <= lent && t1b-s1b[x] >= 0){
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
