#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
string s1[200002],s2[200002],t1,t2;
map<char,vector<int> > vis;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		vis[s1[i][0]+s2[i][0]].push_back(i);
	}
	while(m--){
		cin>>t1>>t2;
		ans=0;
		for(int i=0;i<t1.size();i++){
			if(t1.substr(0,i)!=t2.substr(0,i))continue;
			for(int j=0;j<vis[t1[i]+t2[i]].size();j++){
				if(t1.substr(i,s1[vis[t1[i]+t2[i]][j]].size())==s1[vis[t1[i]+t2[i]][j]]&&t2.substr(i,s1[vis[t1[i]+t2[i]][j]].size())==s2[vis[t1[i]+t2[i]][j]]){
					if(t1.substr(i+s1[vis[t1[i]+t2[i]][j]].size(),t1.size()-i-s1[vis[t1[i]+t2[i]][j]].size())==t2.substr(i+s1[vis[t1[i]+t2[i]][j]].size(),t1.size()-i-s1[vis[t1[i]+t2[i]][j]].size())){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
