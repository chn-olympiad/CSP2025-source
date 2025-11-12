#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
using namespace std;
string t1,t2;
ll n,q,ans;
map<string,string>p;
map<string,bool>vis;
void dfs(string now){
	//cout<<now<<' '<<t2<<' '<<(now==t2)<<endl;
	if(now==t2) ++ans;
	for(ll len=1;len<=now.size();++len){
		for(ll i=0;i+len<=now.size();++i){
			ll r=i+len;
			string str;
			for(ll k=i;k<=r;++k) str=str+now[k];
			//cout<<str<<endl;
			if(p.find(str)!=p.end()){
				string q=p[str];
				string next=now;
				ll nw=0;
				for(ll k=i;k<=r;++k){
					next[k]=q[nw];
					nw++;
				}
				dfs(next);
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;++i){
		string s1,s2;
		cin>>s1>>s2;
		p[s1]=s2;
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		dfs(t1);
		cout<<ans<<endl;
	}
	return 0;
}
