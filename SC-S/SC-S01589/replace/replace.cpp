#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,q;
map<string,string>mp;
string t1,t2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b; 
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl; 
			continue;
		}
		int l=0,r=t1.size()-1;
		while(t1[l]==t2[l]){
			l++;
		}
		while(t1[r]==t2[r]){
			r--;
		}
		int ans=0;
		for(int i=0;i<=l;i++){
			for(int j=r;j<t1.size();j++){
				if(mp[t1.substr(i,j-i+1)]==t2.substr(i,j-i+1)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
