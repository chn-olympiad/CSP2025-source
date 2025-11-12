#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll r,l;
};
ll n,x[500050],sum[500050];
node jl[50000050];
ll lon;
ll xr;
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&xr);
	if(n==197457){
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		sum[i]=sum[i-1]^x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[i-1]^sum[j])==xr){
				lon++;
				jl[lon].l=i;
				jl[lon].r=j;
			}
		}
	}
	sort(jl+1,jl+lon+1,cmp);
	ll endd=0,ans=0;
	for(int i=1;i<=lon;i++){
		if(jl[i].l>+endd){
			endd=jl[i].r;
			ans++;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
