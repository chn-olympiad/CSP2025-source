//T3:replace.cpp
#include<bits/stdc++.h>
using namespace std;
vector<pair<string,string> >mp;
string t,r;
int ans;
int n,f;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>f>>n;
	for(int i=1;i<=f;i++){
		string target, replacement;
		cin>>target>>replacement;
		mp.emplace_back(make_pair(target,replacement));
	}
	for(int __tadfas=1;__tadfas<=n;__tadfas++){
		cin>>t>>r;
		for(pair<string, string> cur:mp){
			string tar = cur.first;
			string rep = cur.second;
			string nowx = t;
			if(nowx.find(tar) != nowx.npos){
				string::size_type tt = nowx.find(tar);
				string before = nowx.substr(0,tt);
				string after = nowx.substr(tt+tar.size(),nowx.npos);
				nowx = before+rep+after;
				if(nowx == r) ans++;
			}
		}
		cout<<ans<<"\n";
		ans = 0;
	}
	return 0;
}