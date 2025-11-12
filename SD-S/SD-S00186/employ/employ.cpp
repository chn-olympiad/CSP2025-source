#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<' '<<x<<'\n'
#define int long long
const int N=1e5+5;
const int P=998244353;
int n,m,a[N];
char s[N];
int p[20],vis[20],ans;
void dfs(int ii,int e,int sum) {
	
	if(ii==n) {
		if(sum>=m){
		ans++;
		} 
		return ;
	}
	if(s[ii+1]=='0') {
		for(int i=1; i<=n; i++) {
			if(vis[i])continue;
			vis[i]=1;
			p[ii+1]=i;
			dfs(ii+1,e+1,sum);
			vis[i]=0;
		}
	} else {
		for(int i=1; i<=n; i++) {
			if(vis[i])continue;
			if(e>=a[i]){
				vis[i]=1;
				p[ii+1]=i;
				dfs(ii+1,e+1,sum);
				vis[i]=0;
			}else{
				vis[i]=1;
				p[ii+1]=i;
				dfs(ii+1,e,sum+1);
				vis[i]=0;
			}			
		}		
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%s",s+1);
	int ma=0;
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		ma=max(ma,a[i]);
	}
	if(n<=18) {
		dfs(0,0,0);
		printf("%lld",ans);
		return 0;
	}
	
	return 0;
}
