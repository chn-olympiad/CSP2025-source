#include<bits/stdc++.h>
using namespace std;

int n,q;
map<pair<string,string>,vector<pair<string,string> > > mp;
string s1, s2;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); 
	cin>>n>>q;
	string s3,s4,s5,s6,mid,mid2;
	for(int i=1,sz;i<=n;++i) {
		cin>>s1>>s2;
		if(s1==s2) continue;
		sz = s1.size();
		s3 = ""; s4 = ""; s5 = ""; s6 = "";
		for(int i=0;i<sz;++i) {
			if(s1[i]==s2[i]) s3+=s1[i];
			else break;
		}
		int r;
		for(r=sz-1;r>=0&&s1[r]==s2[r];--r);
		for(int i=r+1;i<sz;++i) s4+=s1[i];
		for(int i=s3.size();i<=r;++i) {
			s5+=s1[i];
			s6+=s2[i];
		}
		mp[{s5,s6}].push_back({s3,s4});
	}
	while(q--) {
		int ans = 0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size() || s1==s2) {
			cout<<0<<'\n';
			continue;
		}
		int l,r,sz=s1.size();
		for(l=0;l<sz&&s1[l]==s2[l];++l);
		for(r=sz-1;r>=0&&s1[r]==s2[r];--r);
		mid = "";
		for(int i=l;i<=r;++i) {
			mid += s1[i];
			mid2 += s2[i];
		}
		auto &x = mp[{mid,mid2}];
		for(auto &y : x) {
			int sz2 = y.first.size();
			bool flag = true;
			for(int i=0;i<sz2;++i) {
				if(y.first[i] != s1[l-sz2+i]) {
					flag = false;
					break;
				}
			}
			if(!flag) continue;
			sz2 = y.second.size();
			for(int i=0;i<sz2;++i) {
				if(y.second[i] != s1[r+1+i]) {
					flag = false;
					break;
				}
			}
			if(flag) {
				++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}