#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
vector<int>v;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(auto c:s) {
		if(!isdigit(c)) continue;
		v.push_back(c-'0');
	}
	sort(v.begin(),v.end(),greater<>());
	for(auto num:v) cout<<num;
	return 0;
}