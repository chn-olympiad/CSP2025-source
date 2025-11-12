#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
long long ans;
char s[501];
int a[501],b[501],vis[501];
void dfs(int x){
	if(x==n+1){
		int qt=0,lq=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'&&qt<a[b[i+1]]){
				lq++;
			}if(s[i]=='0'||qt>=a[b[i+1]]){
				qt++;
			}
		}
		if(lq>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[i]=x;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==n){
		ans=1;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				printf("0");
				return 0;
			}if(a[i+1]==0){
				printf("0");
				return 0;
			}
			ans*=(i+1);
			ans%=mod;
		}
		printf("%lld",ans);
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
/*xgw120121 loves kzh
fanxing1124 loves yr
dpf_qyn_QwQ loves qyn*/
