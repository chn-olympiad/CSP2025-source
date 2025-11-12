//ALL FOR MYSELF, NOT ANYONE ELSE
//±©Á¦ 
#include<bits/stdc++.h>
//#define TERRY_MC
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,q;
pair<string,string> s[N];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef TERRY_MC
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
#endif
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s[i].first>>s[i].second;
	}
	string t1,t2;
	while(q--) {
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<t1.size();j++) {
				if(t1[j]==s[i].first[0]&&t1.substr(j,s[i].first.size())==s[i].first&&t1.substr(0,j)+s[i].second+t1.substr(j+s[i].second.size())==t2) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

