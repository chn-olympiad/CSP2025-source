#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=1e5+10;
int T;
ll n;
ll a[N][5];
ll p[5];
ll fa[N];
ll fb[N];
ll fc[N];
ll bka,bkb,bkc;
ll suma,sumb,sumc;
ll ans;
ll ansx;
void x_clear(){
	for(ll i=1;i<=bka;i++){
		fa[i]=0;
	}
	for(ll i=1;i<=bkb;i++){
		fb[i]=0;
	}
	for(ll i=1;i<=bkc;i++){
		fc[i]=0;
	}
	p[1]=0;
	p[2]=0;
	p[3]=0;
	return ;
}
void x_slove(){
	scanf("%lld",&n);
	ansx=0;
	bka=0;
	bkb=0;
	bkc=0;
	ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		ansx+=max({a[i][1],a[i][2],a[i][3]});
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			p[1]++;
			fa[++bka]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
		}
		if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			p[2]++;
			fb[++bkb]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
		}
		if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
			p[3]++;
			fc[++bkc]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
		}
	}
	if(p[1]<=n/2&&p[2]<=n/2&&p[3]<=n/2){
		cout<<ansx<<"\n";
		x_clear();
		return ;
	}
	suma=sumb=sumc=ansx;
	if(p[1]>n/2){
//		suma=ansx;
		sort(fa+1,fa+bka+1);
		for(int i=1;i<=p[1]-n/2;i++){
			suma-=fa[i];
		}
		ans=max(ans,suma);
	}
	if(p[2]>n/2){
//		sumb=ansx;
		sort(fb+1,fb+bkb+1);
		for(int i=1;i<=p[2]-n/2;i++){
			sumb-=fb[i];
		}
		ans=max(ans,sumb);
	}
	if(p[3]>n/2){
//		sumc=ansx;
		sort(fc+1,fc+bkc+1);
		for(int i=1;i<=p[3]-n/2;i++){
			sumc-=fc[i];
		}
		ans=max(ans,sumc);
	}
//	cout<<p[1]<<" "<<p[2]<<" "<<p[3]<<"\n";
	x_clear();
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		x_slove();
	}
	return 0;
}
/*
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
*/
