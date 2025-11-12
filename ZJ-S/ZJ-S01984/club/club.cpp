#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+7;
ll _,n,a[N],b[N],c[N],a2[N],b2[N],c2[N],cnta,cntb,cntc,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&_);
	while(_--){
		scanf("%lld",&n);
		cnta=cntb=cntc=ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ans+=a[i];
				cnta++;
				a2[cnta]=a[i]-max(b[i],c[i]);
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				ans+=b[i];
				cntb++;
				b2[cntb]=b[i]-max(a[i],c[i]);
			}
			else if(c[i]>=b[i]&&c[i]>=a[i]){
				ans+=c[i];
				cntc++;
				c2[cntc]=c[i]-max(b[i],a[i]);
			}
		}
		if(cnta*2>n){
			sort(a2+1,a2+cnta+1);
			for(int i=1;i+n/2<=cnta;i++){
				ans-=a2[i];
			}
		}
		else if(cntb*2>n){
			sort(b2+1,b2+cntb+1);
			for(int i=1;i+n/2<=cntb;i++){
				ans-=b2[i];
			}
		}
		else if(cntc*2>n){
			sort(c2+1,c2+cntc+1);
			for(int i=1;i+n/2<=cntc;i++){
				ans-=c2[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
