#include<bits/stdc++.h>
using namespace std;
long long n,m,c[510],ans,vis[510],p=998244353;
string s;
void dfs(int x,int a,int b,int cnt){
	if(x>=cnt){
		if(b>=m)ans++,ans%=p;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		if(c[i]<a){
			dfs(x,a+1,b,cnt-1);
			continue;
		}
		vis[i]=1;
		if(s[x]=='0')dfs(x+1,a+1,b,cnt);
		else dfs(x+1,a,b+1,cnt);
		vis[i]=0;
	}
} 
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>s;
  for(int i=1;i<=n;i++)cin>>c[i];
  dfs(0,0,0,n);
  cout<<ans;
  return 0;
}
