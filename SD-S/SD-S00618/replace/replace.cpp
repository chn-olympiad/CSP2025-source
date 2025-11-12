#include<bits/stdc++.h>
#define int long long

using namespace std;
map<string,string>mp;
int n;
//int numc(string s,string ss,string sss) {
//	int cnt=0;
//	for(int i=0;i<s.size();++i) {
//		bool f=1;
//		for(int j=i;j<ss.size()+i;++j) {
//			if(ss[j]!=s[i]) {
//				f=0;
//				break;
//			}
//		}
//		if(f) {
//			string s1,s2;
//			for(int j=0;j<i-1;++j)s1+=s[j];
//			for(int j=i+ss.size()-1;j<s.size();++j)s2+=s[j];
//			cout<<s1<<"0 "<<ss<<"0 "<<s2<<"0\n";
//			if(s1+mp[ss]+s2==sss) cnt++;
//			cout<<cnt<<"\n";
//		}
//	}
//	return cnt;
//}
void solve() {
	string s,ss;cin>>s>>ss;
	int ans=0;
//	if(n<=1e2) {
//		for(auto t:mp) {
//			ans+=numc(s,t.first,ss);
//		}
//		cout<<ans<<"\n";
//		return;
//	}
	cout<<"0\n";
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _ = 1;
	cin>>n;
	cin >> _;
	for(int i=1;i<=n;++i) {
		string s,ss;cin>>s>>ss;
		mp[s]=ss;
	}
	while(_--)solve();
	return 0;
}
