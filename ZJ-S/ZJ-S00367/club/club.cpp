#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct sati {
	ll a[5],al[5];
};
ll n;
ll nco[4];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int prime[5]= {1,2,3,5};
	ll t;
	scanf("%d",&t);
	while(t--) {
		sati sa[100005];
		scanf("%d",&n);
		for(ll i=0; i<n; i++) {
			scanf("%ld%ld%ld",&sa[i].a[1],&sa[i].a[2],&sa[i].a[3]);
			long long max1=-1,max2=-1;
			sa[i].al[1]=0;
			sa[i].al[2]=0;
			sa[i].al[3]=0;
			for(int k=1; k<=3; k++) {
				if(sa[i].a[k]>max1) {
					sa[i].al[3]=sa[i].al[2];
					sa[i].al[2]=sa[i].al[1];
					sa[i].al[1]=k;
					max2=max1;
					max1=sa[i].a[k];
				} else if(sa[i].a[k]>max2) {
					sa[i].al[3]=sa[i].al[2];
					sa[i].al[2]=k;
					max2=sa[i].a[k];
				} else {
					sa[i].al[3]=k;
				}
			}
		}
		nco[1]=0;
		nco[2]=0;
		nco[3]=0;
		ll sum=0;
		for(ll i=0; i<n; i++) {
			ll p=sa[i].al[1];
			ll tyr=1;
			for(ll k=1; k<=3; k++)
				if(nco[k]==n/2) {
					tyr*=prime[k];
				}
			if(tyr%prime[sa[i].al[1]]==0) {
				p=sa[i].al[2];
				if(tyr%prime[sa[i].al[2]]==0) {
					p=sa[i].al[3];
				}
			}
			ll cnum=sa[i].a[p];
			for(ll j=i+1; j<n; j++) {
				int q=sa[j].al[1];
				if(tyr%prime[sa[j].al[1]]==0) {
					q=sa[j].al[2];
					if(tyr%prime[sa[j].al[2]]==0) {
						q=sa[j].al[3];
					}
				}
				if(sa[i].a[p]<sa[j].a[q]) {
					p=q;
					swap(sa[i],sa[j]);
				}
			}
			nco[p]++;
			sum+=sa[i].a[p];
		}
		printf("%d",sum);
		printf("\n");
	}
return 0;
}