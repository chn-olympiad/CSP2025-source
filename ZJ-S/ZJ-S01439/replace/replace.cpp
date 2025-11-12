#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,q;
string s,s1,s2;
pair<pair<int,int>,pair<int,int> >p[101010];
void solve(int x) {
	for(int i=1; i<=x; i++)cout<<"0\n";
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>10000) {
		solve(q);
		return 0;
	}
	for(int i=1; i<=n; i++) {
		cin>>s;
		int lb,rb;
		for(int j=0; j<s.size(); j++) {
			if(s[j]=='b') {
				lb=j;
				break;
			}
			if(s[j]!='a'&&s[j]!='b') {
				solve(q);
				return 0;
			}
		}
		p[i].first.first=lb-0,p[i].first.second=s.size()-lb-1;
		cin>>s;
		for(int j=0; j<s.size(); j++) {
			if(s[j]=='b') {
				rb=j;
				break;
			}
			if(s[j]!='a'&&s[j]!='b') {
				solve(q);
				return 0;
			}
		}
		p[i].second.first=rb-0,p[i].second.second=s.size()-rb-1;
	}
	while(q--) {
		cin>>s1;
		int lb,rb;
		bool os=0;
		for(int j=0; j<s1.size(); j++) {
			if(s1[j]=='b') {
				lb=j;
				break;
			}
			if(s1[j]!='a'&&s1[j]!='b') {
				os=1;
				break;
			}
		}
		cin>>s2;
		for(int j=0; j<s2.size(); j++) {
			if(s2[j]=='b') {
				rb=j;
				break;
			}
			if(s1[j]!='a'&&s1[j]!='b') {
				os=1;
				break;
			}
		}
		if(s1.size()!=s2.size()||os) {
			cout<<"0\n";
			continue;
		}
		int on=s1.size(),ans=0;
		for(int i=1; i<=n; i++) {
			if(p[i].first.first<=lb&&p[i].first.second<=on-lb-1&&p[i].second.first-p[i].first.first+lb==rb) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
