#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ans=0;
map <string ,string>mp;
void saf(string x,string f){
	ans=0;
	for(auto i:mp){
		string a=i.first,b=i.second;
		if(a.size()>x.size())continue;
		for(int i=0;i<=x.size()-a.size();i++){
			if(x.substr(i,a.size())==a){
				string ne=x.substr(0,i)+b+x.substr(i+a.size(),x.size()-a.size()-i);
				if(f==ne){
					ans++;
				}
			}
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	//cout<<"------1ready------\n";
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	//cout<<"------2ready------\n";
	for(int i=1;i<=q;i++){
		string f,t;
		cin>>f>>t;
		saf(f,t);
		cout<<ans<<"\n";
	}
	return 0;
}

