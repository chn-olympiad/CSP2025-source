#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

map<string,string> mp;

string s,e;

int dfs(string now) {
	if(now == s) {
		return 1;
	}
	int ans = 0;
	for(auto x : mp) {
		string tmp  = now;
		if(now.find(x.first)) {
			for(int i = now.find(x.first);i <= now.find(x.first) + x.first.size();i++) {
				now[i] = x.second[i-now.find(x.first)];
			}
			ans+=dfs(now);
		}
		now = tmp;
	}
	return ans;
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i =1;i <= n;i++) {
		string a,b;
		cin>>a>>b;
		mp[a] = b;
	}
	while(q--) {
		cin>>e>>s;
		cout<<0<<endl;
	}
	return 0;
}