#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c[505],ans,a[505],fac[505];
char s[505];
bool vis[505];
const ll mod=998244353;
void dfs(int i){
	if(i==n+1){
		int cnt=0,la=0;
		for(int j=1;j<=n;j++){
			if(la>=c[a[j]]){
				la++;
			}
			else if(s[j]=='1'){
				cnt++;
			}
			else if(s[j]=='0'){
				la++;
			}
		}
		if(cnt>=m){
			ans++;
		}
		return;
	}
	for(int j=1;j<=n;j++){
		if(vis[j]==0){
			vis[j]=1;
			a[i]=j;
			dfs(i+1);
			vis[j]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i;
		fac[i]%=mod;
		scanf("%lld",&c[i]);
	}
	if(m==1){
		ll ans=0;
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(s[j]=='0'){
					cnt++;
				}
				else if(c[i]>cnt){
					ans+=fac[n-1];
					ans%=mod;
				}
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	dfs(1);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
