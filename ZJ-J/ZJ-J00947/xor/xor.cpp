#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n=0,k=0,a[500005]={},f[500005]={};
ll cnt=0,last=0,ans=0;
struct node{
	ll s,e;
}q[1000005];
bool cmp(node x,node y){
	if (x.s==y.s){
		return x.e-x.s<y.e-y.s;
	}
	else{
		return x.s<y.s;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		f[i]=f[i-1]^a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			ll x=f[j]^f[i-1];
			if (x==k){
				cnt++;
				q[cnt].s=i;
				q[cnt].e=j;
			}
		}
	}
	sort(q+1,q+cnt+1,cmp);
	for (int i=1;i<=cnt;i++){
		if (last<q[i].s){
			ans++;
			last=q[i].e;
		}
	}
	printf("%lld",ans);
	return 0;
}
