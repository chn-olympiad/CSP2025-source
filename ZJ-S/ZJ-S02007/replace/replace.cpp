#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans;
string s[200005],e[200005];
bool vis[200005],vis1[200005];
void dfs(string a,string b){
//	_sleep(100);
//	cout<<a<<' '<<b<<'\n';
	if(a==b){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		if(a.find(s[i])==string::npos) continue;
		for(int j=0;j<a.size();j++){
			if(j+s[i].size()>a.size()) break;
			string k=a.substr(j,s[i].size());
			if(k==s[i]){
				if(vis1[j]) continue;
				string l=a;
				for(int k=j;k<j+s[i].size();k++) l[k]=e[i][k-j];
	//			cout<<t<<'\n';
				vis[i]=1;
				vis1[j]=1;
				dfs(l,b);
				vis[i]=0;
				vis1[j]=0;
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i]>>e[i];
	while(m--){
		for(int i=1;i<=n;i++) vis[i]=0;
		ans=0;
		string st,ed;
		cin>>st>>ed;
		if(st.size()!=ed.size()) cout<<"0\n";
		else{
			dfs(st,ed);
			cout<<ans<<'\n';
		}
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
