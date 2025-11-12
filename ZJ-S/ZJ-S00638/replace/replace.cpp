#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,le[200005],ans;
string q1,q2,fr[200005],to[200005];
void dfs(string x,int t){
	if(t){
		if(q2==x) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		int l=x.find(fr[i]);
		if(l!=-1) x.replace(l,le[i],to[i]),dfs(x,1),x.replace(l,le[i],fr[i]);
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>fr[i]>>to[i];
		le[i]=fr[i].size();
	}
	while(m--){
		cin>>q1>>q2;
		ans=0;
		dfs(q1,0);
		cout<<ans<<"\n";
	}
	return 0;
}