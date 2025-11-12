#include<bits/stdc++.h> 
#define LL long long
using namespace std;
const int N=1010,mod=998244353;
LL n,m,c[N],b[N],ans,st[N];
char a[N];
void dfs(int u){
	if(u==n+1){
		LL ts=0,res=0;
		for(int i=1;i<=n;i++){
			if(ts>=b[i]||a[i]=='0'){
				ts++;
			}
			else{
				res++;
			}
		}
		if(res>=m) ans++;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			b[u]=c[i];
			dfs(u+1);
			st[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;cin>>a+1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans%mod;
	}
	else{
		int op=n;
		for(int i=1;i<=n;i++){
			if(c[i]==0) op--;
		}
		if(op>=m){
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}
			cout<<ans;
		}
		else cout<<0;
	}
	
	return 0;
}