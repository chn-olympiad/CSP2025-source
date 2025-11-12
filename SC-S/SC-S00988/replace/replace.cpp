#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 2e5 + 5;
int n, q;
string s1[N], s2[N];
int main(){
	freopen("replace.in", "r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
	} 
	while(q--){
		int ans = 0; 
		string t1, t2;
		cin >> t1 >> t2;
		int len = 0;
		for(int i = 0; i < t1.size(); i++){
			if(t1[i] != t2[i]) len++;
		}
		for(int l = len; l <= t1.size(); l++){
			for(int i = 0; i < t1.size() - l + 1; i++){
				int j = i + l - 1;
				for(int k = 1; k <= n; k++){
					if(l != s1[k].size()) continue;
					int now = 0, flag = 0;
					for(int p = i; p <= j; p++){
						if(t1[p] != s1[k][now] || t2[p] != s2[k][now]){
							flag = 1;
							break;
						}	
						now++;
					}
					if(!flag) ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}