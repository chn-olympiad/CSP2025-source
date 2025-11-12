#include<bits/stdc++.h>
#define For(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;
int n,m,a[510],ans=0;
string s;
bool vis[510];
void dfs(int x,int sum,int tot){
	if(x>n){
		if(sum>=m) ++ans,ans%=998244353;
		return ;
	}
	For(i,1,n){
		if(vis[i]) continue;
		if(a[i]<=tot||s[x-1]=='0'){
			vis[i]=1;
			dfs(x+1,sum,tot+1);
			vis[i]=0;
		}
		else{
			vis[i]=1;
			dfs(x+1,sum+1,tot);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	For(i,1,n) cin>>a[i];
	dfs(1,0,0);
	cout<<ans<<"\n";
	return 0;
}

