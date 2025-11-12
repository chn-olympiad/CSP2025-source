#include<bits/stdc++.h>
using namespace std;
const int N=510,MOD=998244353;
int n,m,ans,res[N],num[N];
string str;
bool st[N];
void dfs(int u,int p){
	if(u-p>n-m){
		return ; 
	}
	if(u==n){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!st[i]){
			st[i]=1;
			num[u]=i;
			if(str[u]=='1'&&u-p<res[i]) dfs(u+1,p+1);
			else dfs(u+1,p);
			st[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++) cin>>res[i];
	sort(res+1,res+n+1);
	if(n==m){
		cout<<0;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
