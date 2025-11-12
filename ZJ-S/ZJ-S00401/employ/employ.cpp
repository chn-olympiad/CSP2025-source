#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[510],ans;
bool vis[10010];
string s;
void dfs(int x,int f,int num){
	if(x==n){
		if(num>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[x]=='0' or f>=a[i]){
				dfs(x+1,f+1,num);
			}else{
				dfs(x+1,f,num+1);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	if(n<=30) cout<<ans;
	else cout<<0;
	return 0;
}

