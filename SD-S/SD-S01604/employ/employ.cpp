#include <bits/stdc++.h>
using namespace std;
inline long long read() { long long x = 0 , f = 1; char c = getchar(); while(c < '0' || '9' < c) {	if(c == '-') f = -1; c = getchar(); } while('0' <= c && c <= '9') { x = x*10 + c-'0'; c = getchar(); } return x * f; }
const int N=505;
const int mod=998244353;
int n,m,a[N],p[N],su;
bool SPA=1,vis[N];
char s[N];
long long ans;
void dfs(int now){
	if(now>n){
		su=0;
		for(int i=1;i<=n;i++)
			if(a[p[i]]<=i-1-su);
			else if(s[i]=='1')
				su++;
		if(su>=m)
			ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			vis[i]=1,p[now]=i,dfs(now+1),vis[i]=0;
}
signed main() {
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		if(s[i]!='1'){
			SPA=0;
			break;
		} 
	if(SPA){
		ans=1;
		for(int i=2;i<=n;i++)
			ans*=i,ans%=mod;
		cout<<ans;
	}
	else
		dfs(1),cout<<ans;
	return 0;
}
