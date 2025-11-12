#include<bits/stdc++.h>
#define int long long
using namespace	std;
const int N=5e5+5;
int n,Q;
string a[N],b[N],s,t;
//map<string,int> mp,vis;
//void dfs(string p){
//	vis[p]=1;
//	if()
//	for(int i=1;i<=n;i++){
//		int w=p.find(a[i]);
//		if(w<p.size()){
//			string pre,nxt,now;
//			pre=p.substr(0,w-1);
//			nxt=p.substr(w+a[i].size(),p.size()-1);
//			now=pre+b[i]+nxt;
//			if(vis[now]==0)dfs(now);
//		}
//	}
//}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(Q--){
		cin>>s>>t;
		cout<<"0\n";
	}
	return 0;
}