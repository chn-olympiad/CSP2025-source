#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e2+10,mod=998244353;
int n,m,c[N],st[N],a[N],ans;
char s[N];
void dfs(int u){
	if(u>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=a[i]||s[i]=='0') cnt++;
		}
		if(n-cnt>=m) ans++,ans%=mod;
	}
	for(int i=1;i<=n;i++){
		if(st[i]) continue;
		st[i]=1,a[u]=c[i];
		dfs(u+1);
		st[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}