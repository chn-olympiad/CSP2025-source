#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+15;
int t,n,q;
map<string,string>mp; 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string s,t;
		cin>>s>>t;
		mp[s]=t;
	}
	while(q--){
		string s;
		cin>>s>>t;
		int n=s.size();
//		for(int i=0;i<n;++i){
//			for(int j=i;j<n;++j){
//				
//			}
//		}
		cout<<0<<"\n";
	}
	return 0;
}
