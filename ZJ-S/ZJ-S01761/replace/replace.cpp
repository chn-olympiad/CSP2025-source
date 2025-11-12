#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
int n,q;
string x,y;
map<string,string> mp;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		mp[x]=y;
	}
	while(q--){
		cin>>x>>y;
		int ans=0;
		for(auto i:mp){
			int cnt=x.find(i.first);
			string num=x;
			if(cnt>=0 && cnt<x.size()){
				for(int j=cnt;j<cnt+i.first.size();j++) num[j]=i.second[j-cnt];
				//cout<<num<<" "<<y<<"\n";
				ans+=(num==y);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}