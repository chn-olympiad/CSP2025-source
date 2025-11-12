#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ans;
unsigned long long x;
//unsigned long long H1[20010],H2[20010],p[20010],P=31;
//unordered_map <unsigned long long,bool> mp;
map <string,bool> mp;
string s1[20010],s2[20010],t1,t2;
bool f[20010];
void dfs(string r) {
	if(r==t2) {
		ans++;
		return;
	}
//	cout<<r<<"\n";
	for(int i=1;i<=n;i++) {
		if(!f[i]) for(int j=0;j+s1[i].size()-1<t1.size();j++) {
			if(r.substr(j,s1[i].size())==s1[i]) {
				for(int u=1;u<=s1[i].size();u++) {
					r[u+j-1]=s2[i][u-1];
				}
				f[i]=1;
				dfs(r);
				f[i]=0;
				for(int u=1;u<=s1[i].size();u++) {
					r[u+j-1]=s1[i][u-1];
				}
			}
		}
	}
	return;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++) {
		cin>>t1>>t2;
		ans=0;
		mp.clear();
		dfs(t1);
		cout<<ans<<"\n";
	}
	return 0;
}