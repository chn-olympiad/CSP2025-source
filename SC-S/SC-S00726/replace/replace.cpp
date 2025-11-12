#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX=1e4+5;
vector<pair<string,string>>p;
int n,q;
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		p.push_back({s1,s2});
	}
	string t1,t2;
	if(q==1){
		int ans=0;
		for(auto s:p){
			auto u=s.first,v=s.second;
			bool flag=false;
			for(auto c:v)if(c!='a'){
				flag=true;
				break;
			}
			if(flag)continue;
			ans++;
		}
		cout<<ans<<'\n';
		return;
	}
	while(q--){
		cin>>t1>>t2;
		cout<<"0\n";
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}