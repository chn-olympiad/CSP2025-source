#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509,mod=998244353;
int n,m,flag=1;
int s[N],p[N],p1[N],vis[N];
ll dp[N][N];
ll ans;
ll fr(){
	ll x=0;
	char c=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x;
}
bool check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(i-1-sum<p1[i]&&s[i]) sum++;
	}
	return sum>=m;
}
void dfs(int k){
	if(k==n+1){
		if(check()) ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) vis[i]=1,p1[k]=p[i],dfs(k+1),vis[i]=0;
	}
	return ;
}
void solve1(){
	dfs(1);
	printf("%lld",ans);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=fr(),m=fr();
	char c=getchar();
	int tot=0;
	while(c=='0'||c=='1'){
		s[++tot]=c-'0';
		if(s[tot]==0) flag=0;
		c=getchar();
	}
	for(int i=1;i<=n;i++) p[i]=fr();
	if(n<=10) solve1();
	return 0;
}

