#include<bits/stdc++.h>
using namespace std;
#define int long long
const int _=5*1e6+10;
int n,T,i;
string s1[_],s2[_],fx,S,qx,zx;
queue<string> d;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>T;
	for(i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(T--){
		map<string,int> vis,f;
		cin>>qx>>zx;
		int ans=0;
		for(i=1;i<=n;i++){
			for(int j=0;j+s1[i].size()-1<qx.size();j++){
				if(qx.substr(j,s1[i].size())==s1[i]){
					S="";
					if(j>0)
						S=qx.substr(0,j);
					S+=s2[i];
					if(j+s1[i].size()<qx.size())
						S+=qx.substr(j+s1[i].size(),
						qx.size()-(j+s1[i].size()));
					if(S==zx) ans++;
					if(!vis[S]){
						vis[S]=1;
						d.push(S);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}
