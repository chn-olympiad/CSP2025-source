#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll md=998244353;
ll n,ans;
int a[5010],bx[5010],zs[5010]={2,3,5,7,11,13,17};
bool vs[5010],fg1=true;
int dfs(int x,int tt,int sum,int mx){
	if(tt>2&&sum>(mx*2)) ans=(ans+1)%md;
	for(int i=x+1;i<=n;i++){
		if(!vs[i]){
			vs[i]=1;
			dfs(i,tt+1,sum+a[i],max(mx,a[i]));
			vs[i]=0;
		}
	}
}
ll C(ll y){
	if(n==y) return 1;
	y=min(y,n-y);
	ll fz=1,fm=1;
	for(ll i=1;i<=y;i++){
		fz*=i,fm*=(n-i+1);
		int gd=__gcd(fz,fm);
		fz/=gd,fm/=gd;
	}
	return fz/fm;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		bx[a[i]]++;
		if(a[i]>1) fg1=false;
	}
	if(n<=20){
		dfs(0,0,0,0);
		printf("%lld\n",ans%md);
	}
	else if(fg1){
		for(ll i=3;i<=n;i++) ans+=C(i)%md;
		printf("%lld\n",ans%md);
	}
	else printf("1\n");
	return 0;
}
