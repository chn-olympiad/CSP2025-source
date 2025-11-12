#include<bits/stdc++.h>
#define Maxn 100100
using namespace std;
long long ans;
int t,n,sa,sb,sc,a,b,c;
int al[Maxn],bl[Maxn],cl[Maxn],dj;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		ans=0,sa=0,sb=0,sc=0;
		for(int j=1;j<=n;j++){
			scanf("%d %d %d",&a,&b,&c);
			if(a>=b){
				if(a>=c){
					ans+=a;
					al[sa++]=a-max(b,c);
				}
				else{
					ans+=c;
					cl[sc++]=c-max(b,a);
				}
			}
			else{
				if(b>=c){
					ans+=b;
					bl[sb++]=b-max(a,c);
				}
				else{
					ans+=c;
					cl[sc++]=c-max(b,a);
				}
			}
		}
		if(sa*2>n)sort(al,al+sa);
		if(sb*2>n)sort(bl,bl+sb);
		if(sc*2>n)sort(cl,cl+sc);
		int o=0;
		while(sa*2>n){
			ans-=al[o++];
			sa--;
		}
		while(sb*2>n){
			ans-=bl[o++];
			sb--;
		}
		while(sc*2>n){
			ans-=cl[o++];
			sc--;
		}
		printf("%lld\n",ans);
	}
}
