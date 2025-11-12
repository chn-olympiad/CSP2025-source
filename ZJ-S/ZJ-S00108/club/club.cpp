#include<bits/stdc++.h>
using namespace std;

long long t;
long long n;
struct nod{
	long long fi,se,th,dq;
}a[100010];

long long fir,ser,thr;
long long ans;
long long extb[100010];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t>0){
		t--;//jide chushihua
		ans=0;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			a[i].fi=0;
			a[i].se=0;
			a[i].th=0;
			a[i].dq=0;
			fir=0;
			ser=0;
			thr=0;
			extb[i]=0;
		}
		long long maxr=n/2;
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].fi,&a[i].se,&a[i].th);
		}
		//jinzuidade
		for(long long i=1;i<=n;i++){
			if(a[i].fi>a[i].se){
				if(a[i].fi>a[i].th){
					fir++;
					ans+=a[i].fi;
					a[i].dq=1;
				}else{
					thr++;
					ans+=a[i].th;
					a[i].dq=3;
				}
			}else{
				if(a[i].se>a[i].th){
					ser++;
					ans+=a[i].se;
					a[i].dq=2;
				}else{
					thr++;
					ans+=a[i].th;
					a[i].dq=3;
				}
			}
		}//jianchashifou chaoguo
		if(fir>maxr){//keyidao 2  3
			long long dcr=fir-maxr;
			long long js=0;
			for(long long i=1;i<=n;i++){//zhao zhuanyifeiyongzuixiao
				if(a[i].dq==1){
					js++;
					extb[js]=min(a[i].fi-a[i].se,a[i].fi-a[i].th);
				}
			}
			sort(extb+1,extb+1+js);
			for(long long i=1;i<=dcr;i++){
				ans-=extb[i];
			}
		}
		else if(ser>maxr){
			long long dcr=ser-maxr;
			long long js=0;
			for(long long i=1;i<=n;i++){//zhao zhuanyifeiyongzuixiao
				if(a[i].dq==2){
					js++;
					extb[js]=min(a[i].se-a[i].fi,a[i].se-a[i].th);
				}
			}
			sort(extb+1,extb+1+js);
			for(long long i=1;i<=dcr;i++){
				ans-=extb[i];
			}
		}
		else{
			long long dcr=thr-maxr;
			long long js=0;
			for(long long i=1;i<=n;i++){//zhao zhuanyifeiyongzuixiao
				if(a[i].dq==3){
					js++;
					extb[js]=min(a[i].th-a[i].fi,a[i].th-a[i].se);
				}
			}
			sort(extb+1,extb+1+js);
			for(long long i=1;i<=dcr;i++){
				ans-=extb[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}