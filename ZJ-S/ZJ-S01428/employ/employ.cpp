//8
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans;
string s;
bool vis[20];
int a[20];
void dfs(int st,int tk){
	if(st==n){
		if(n-tk>=m) ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			if(tk<a[i]||s[st]=='0') dfs(st+1,tk+1);
			else dfs(st+1,tk);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i) cin>>a[i];
	dfs(0,0);
	cout<<ans;
	return 0;
}
