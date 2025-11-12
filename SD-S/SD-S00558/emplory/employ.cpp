#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e2,mod=998244353;
int n,m,cntt;
string s;
int a[N+5],t[N+5],vis[N+5];
ll ans;
void dfs1(int x,int cnt,int giveup){
	if(x>n&&cnt>=m){
		ans++;
		ans%=mod;
		return ;
	}
	if(x>n&&cnt<m) return ;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(s[x]=='1'){
			if(t[x]+giveup>=a[i]) dfs1(x+1,cnt,giveup+1);
			else dfs1(x+1,cnt+1,giveup);
		}
		else dfs1(x+1,cnt,giveup);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<s.size();i++){
		if(s[i]=='0') t[i]=t[i-1]+1;
		else t[i]=t[i-1];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0) cntt++;
	} 
	if(n<=40) dfs1(1,0,0);
	else{
		if(n-cntt<m){
			cout<<0;
			return 0;
		} 
		ans=1;
		for(int i=n-cntt;i>=2;i--){
			ans=ans*i%mod;
		}
	}
	cout<<ans%mod;
	return 0;
}

