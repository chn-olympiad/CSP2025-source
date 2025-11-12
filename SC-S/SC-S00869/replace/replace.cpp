#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
const int N=2e5+5;
int n,q;
pair<string,string> s[N];
string t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>s[i].first>>s[i].second;
	while(q--){
		cin>>t1>>t2;
		int r=0;
		for(int i=1;i<=n;++i){
			if(t1.find(s[i].first)!=-1){
				string tt=t1;
				int p=tt.find(s[i].first);
				tt.erase(tt.begin()+p,tt.begin()+p+s[i].first.size());
				tt.insert(p,s[i].second);
				r+=(tt==t2);
			}
		}
		cout<<r<<"\n";
	}
	return 0;
}