#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
bool a[505];
int c[505],n,m,ans,jc[505],vis[505];
void dfs(int k,int now,int fail,int base){
	if(now>=m) return ans+=jc[n+1-k+base]%mod,ans%=mod,void();
	if(k==n+1) return;
	if(a[k]==0) return dfs(k+1,now,fail+1,base+1);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(k+1,now+(a[k]&&(c[i]>fail)),fail+!(a[k]&&(c[i]>fail)),base);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}
