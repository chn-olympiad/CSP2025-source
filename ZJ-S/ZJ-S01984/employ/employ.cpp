#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=507,mod=998244353;
ll ans,cnt,n,m,num,vis[N],a[N],jc[N],c[N];
void d(ll now1,ll now2,ll now3){
	if(now3>=c[now1]||a[now2]==0)now3++;
	if(now2-now3>=m){
		ans+=jc[n-now2];
		ans%=mod;
		return;
	}
	if(n-now3<m)return;
	vis[now1]=1;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		d(i,now2+1,now3);
	}
	vis[now1]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]*=jc[i-1];
		jc[i]%=mod;
	}
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	for(int i=1;i<=n;i++){
		d(i,1,0);
	}
	printf("%lld",ans);
	return 0;
}
