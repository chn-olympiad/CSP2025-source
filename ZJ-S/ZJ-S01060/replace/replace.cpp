#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5+100;
int n,q;
string s1[maxn+100],s2[maxn+100],t1,t2;

void query(){
	int cnt = 0;
	cin >> t1 >> t2;
	if(t1.size() != t2.size()){
		cout << 0 << '\n';
		return;
	}
	for(int i = 1;i <= n;i++){
		string tmp;
		if(s1[i].size() > t1.size()) continue;
		if(s1[i].size() == t1.size() && t1 == s1[i]) tmp = s2[i];
		else if(s1[i].substr(0,t1.size()) == t1)tmp = s2[i] + t1.substr(s2[i].size(),t1.size()-s2[i].size()); 
		else tmp = "";
		if(tmp == t2) cnt++;
		//cout << tmp << '\n';
		//[0,j] [j+1,j+t.size()] [j+1+t.size(),end] 
		for(int j = 0;j < t1.size();j++){
			int pos = j+s1[i].size();
			if(pos >= t1.size()) break;
			string tt = t1.substr(j+1,s1[i].size());
			if(tt != s1[i]) continue;
			string tmp = t1.substr(0,j+1) + s2[i] + t1.substr(pos+1,t1.size()-pos);
			if(tmp == t2) cnt++;
		}
	}
	cout << cnt << '\n';
	return;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
	}
	if(n >= 1000){
		for(int i = 1;i <= q;i++){
			cout << 0 << '\n';
		}
		return 0;
	}
	for(int i = 1;i <= q;i++){
		query();
	}
	return 0;
}
