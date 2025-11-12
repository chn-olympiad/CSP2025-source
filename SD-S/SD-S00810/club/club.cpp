#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+10;
struct cs{
	ll of1,of2,of3;
}m[N][3];
struct ns{
	ll ma1,ma2,ma3;
}a[N];
ll t,n,f[N][3],r[N];
bool cmp(ns x,ns y){
	ll tmp1=x.ma1,tmp2=x.ma2,tmp3=x.ma3,tmp4=y.ma1,tmp5=y.ma2,tmp6=y.ma3;
	if(tmp1>tmp2)
		swap(tmp1,tmp2);
	if(tmp2>tmp3)
		swap(tmp2,tmp3);
	if(tmp4>tmp5)
		swap(tmp4,tmp5);
	if(tmp5>tmp6)
		swap(tmp5,tmp6);
	if(tmp1-tmp4)
		return tmp1>tmp4;
	if(tmp2-tmp5)
		return tmp2>tmp5;
	if(tmp3-tmp6)
		return tmp3>tmp6;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		bool cheat2=false,cheat3=false;
		memset(m,0,sizeof(m));
		memset(f,0,sizeof(f));
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].ma1,&a[i].ma2,&a[i].ma3);
			cheat2|=a[i].ma2;
			cheat3|=a[i].ma3;
		}
		sort(a+1,a+1+n,cmp);
		if(!cheat2&&!cheat3){
			ll s=0;
			for(ll i=1;i<=n/2;i++)
				s+=a[i].ma1;
			printf("%lld\n",s);
			continue;
		}
		for(ll i=1;i<=n;i++){
			if(i==1){
				f[1][0]=a[i].ma1;
				f[1][1]=a[i].ma2;
				f[1][2]=a[i].ma3;
				m[1][0].of1=1;
				m[1][1].of2=1;
				m[1][2].of3=1;
			}
			else{
				if(f[i-1][0]>f[i-1][1]&&f[i-1][0]>f[i-1][2]){
					if(m[i-1][0].of1<n/2){
						f[i][0]=f[i-1][0]+a[i].ma1;
						m[i][0].of1=m[i-1][0].of1+1;
					}
					else if(f[i-1][1]>f[i-1][2]){
						f[i][0]=f[i-1][1]+a[i].ma1;
						m[i][0].of1=m[i-1][1].of1+1;
					}
					else{
						f[i][0]=f[i-1][2]+a[i].ma1;
						m[i][0].of1=m[i-1][2].of1+1;
					}
					if(m[i-1][0].of2<n/2){
						f[i][1]=f[i-1][0]+a[i].ma2;
						m[i][1].of2=m[i-1][0].of2+1;
					}
					else if(f[i-1][1]>f[i-1][2]){
						f[i][1]=f[i-1][1]+a[i].ma2;
						m[i][1].of2=m[i-1][1].of2+1;
					}
					else{
						f[i][1]=f[i-1][2]+a[i].ma2;
						m[i][1].of2=m[i-1][2].of2+1;
					}
					if(m[i-1][0].of3<n/2){
						f[i][2]=f[i-1][0]+a[i].ma3;
						m[i][2].of3=m[i-1][0].of3+1;
					}
					else if(f[i-1][1]>f[i-1][2]){
						f[i][2]=f[i-1][1]+a[i].ma3;
						m[i][2].of3=m[i-1][1].of3+1;
					}
					else{
						f[i][2]=f[i-1][2]+a[i].ma3;
						m[i][2].of3=m[i-1][2].of3+1;
					}
				}
				if(f[i-1][1]>f[i-1][0]&&f[i-1][1]>f[i-1][2]){
					if(m[i-1][1].of1<n/2){
						f[i][0]=f[i-1][1]+a[i].ma1;
						m[i][0].of1=m[i-1][1].of1+1;
					}
					else if(f[i-1][0]>f[i-1][2]){
						f[i][0]=f[i-1][0]+a[i].ma1;
						m[i][0].of1=m[i-1][0].of1+1;
					}
					else{
						f[i][0]=f[i-1][2]+a[i].ma1;
						m[i][0].of1=m[i-1][2].of1+1;
					}
					if(m[i-1][1].of2<n/2){
						f[i][1]=f[i-1][1]+a[i].ma2;
						m[i][1].of2=m[i-1][1].of2+1;
					}
					else if(f[i-1][0]>f[i-1][2]){
						f[i][1]=f[i-1][0]+a[i].ma2;
						m[i][1].of2=m[i-1][0].of2+1;
					}
					else{
						f[i][1]=f[i-1][2]+a[i].ma2;
						m[i][1].of2=m[i-1][2].of2+1;
					}
					if(m[i-1][1].of3<n/2){
						f[i][2]=f[i-1][1]+a[i].ma3;
						m[i][2].of3=m[i-1][1].of3+1;
					}
					else if(f[i-1][0]>f[i-1][2]){
						f[i][2]=f[i-1][0]+a[i].ma3;
						m[i][2].of3=m[i-1][0].of3+1;
					}
					else{
						f[i][2]=f[i-1][2]+a[i].ma3;
						m[i][2].of3=m[i-1][2].of3+1;
					}
				}
				if(f[i-1][2]>f[i-1][1]&&f[i-1][2]>f[i-1][0]){
					if(m[i-1][2].of1<n/2){
						f[i][0]=f[i-1][2]+a[i].ma1;
						m[i][0].of1=m[i-1][2].of1+1;
					}
					else if(f[i-1][0]>f[i-1][1]){
						f[i][0]=f[i-1][0]+a[i].ma1;
						m[i][0].of1=m[i-1][0].of1+1;
					}
					else{
						f[i][0]=f[i-1][1]+a[i].ma1;
						m[i][0].of1=m[i-1][1].of1+1;
					}
					if(m[i-1][2].of2<n/2){
						f[i][1]=f[i-1][2]+a[i].ma2;
						m[i][1].of2=m[i-1][2].of2+1;
					}
					else if(f[i-1][0]>f[i-1][1]){
						f[i][1]=f[i-1][0]+a[i].ma2;
						m[i][1].of2=m[i-1][0].of2+1;
					}
					else{
						f[i][1]=f[i-1][1]+a[i].ma2;
						m[i][1].of2=m[i-1][1].of2+1;
					}
					if(m[i-1][2].of3<n/2){
						f[i][2]=f[i-1][2]+a[i].ma3;
						m[i][2].of3=m[i-1][2].of3+1;
					}
					else if(f[i-1][0]>f[i-1][1]){
						f[i][2]=f[i-1][0]+a[i].ma3;
						m[i][2].of3=m[i-1][0].of3+1;
					}
					else{
						f[i][2]=f[i-1][1]+a[i].ma3;
						m[i][2].of3=m[i-1][1].of3+1;
					}
				}
			}
			r[i]=max(max(r[i-1],f[i][0]),max(f[i][1],f[i][2]));
		}
		printf("%lld\n",r[n]);
	}
	return 0;
}
