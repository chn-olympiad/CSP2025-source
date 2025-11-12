#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
const int inf = 0x7f7f7f7f;

unordered_map<string,string> mp;

int n,m;

string sfind(string s,pair<string,string> che){
	string s_ = s;bool flag = 1;
	for(int i = 0; flag && i < s.size();i++){
		s_ = s;flag = 0;
		for(int j = 0; j < che.first.size();j++){
			if(s[i + j] == che.first[j]){
				s_[i + j] = che.second[j];
			}else{
				flag = 1;
				break;
			}
		}
	}
	return s_;
}

void solve() {
	cin >> n >> m;

	mp.clear();

	for(int i = 1;i <= n; i++){
		string s1,s2;
		cin >> s1 >> s2;
		mp[s1] = s2;
	}

	while(m--){
		string s1,s2;
		cin >> s1 >> s2;
		int res = 0;
		for(auto it : mp){
			string s_ = sfind(s1,it);
			if(s2 == s_){
				res ++;
			} 
		}
		cout << res << endl;
	}

	return;
}

signed main() {
#ifndef online
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
#endif

	int _ = 1;
	while (_--) {
		solve();
	}

	return 0;
}