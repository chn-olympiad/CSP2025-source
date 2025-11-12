#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,q,ans;
map<string,vector<string>>mp;
set<int>st;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string a,b;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		mp[a].push_back(b);
		st.insert(a.size());
	}
	while(q--){
		cin>>a>>b;ans=0;
		int n=a.size();
		if(n!=b.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<n;++i)
			for(const int &len:st){
				if(i+len-1>n)break;
				for(const string&mid:mp[a.substr(i,len)]){
					string c=a.substr(0,i)+mid+a.substr(i+len);
					ans+=(c==b);
				}
			}
		cout<<ans<<'\n';
	}
	return 0;
}
