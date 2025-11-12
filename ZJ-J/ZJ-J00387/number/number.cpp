#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<int> e;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') e.push_back(s[i]-'0');
	}
	sort(e.begin(),e.end(),greater<int>());
	if(e[0]==0) cout<<0;
	else{
		for(auto i:e){
			cout<<i;
		}
	}
	return 0;
}