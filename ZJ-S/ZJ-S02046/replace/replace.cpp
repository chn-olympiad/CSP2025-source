#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
const int M=2e3+10;
const int inf=1e17;
const int mod=998244353;
const int p=31;
int pw[N];
int n,Q;
int ans;
map<string,string> mp;
bool vis[M][M];
void dfs(string s1,string s2,int l,int r){
	if(s1.size()==0){
		return ;
	}
	if(vis[l][r]){
		return ;
	}
	vis[l][r]=1;
	if(mp[s1]==s2){
		ans++;
	}
//	cout<<s1<<' '<<s2<<' '<<ans<<endl;
	if(s1[0]==s2[0]){
		dfs(s1.substr(1,s1.size()-1),s2.substr(1,s2.size()-1),l+1,r);
	}
	if(s1[s1.size()-1]==s2[s2.size()-1]){
		dfs(s1.substr(0,s1.size()-1),s2.substr(0,s2.size()-1),l,r-1);
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<N;i++){
		pw[i]=pw[i-1]*p%mod;
	}
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(Q--){
		memset(vis,0,sizeof(vis));
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			return 0;
		}
		ans=0;
		dfs(s1,s2,0,s1.size()-1);
		cout<<ans<<endl;
	}
	return 0;
}

