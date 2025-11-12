#include<bits/stdc++.h>
#define N 100005
using namespace std;
void r(int&x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}return;
}
int T;
int n;
int mema[N],memb[N],memc[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	r(T);
	while(T--){
		r(n);int ans=0;
		int numa=0,numb=0,numc=0,tmpa=0,tmpb=0,tmpc=0;
		for(int i=1;i<=n;++i){
			r(tmpa),r(tmpb),r(tmpc);
			if(tmpa>tmpb){
				if(tmpb>tmpc){//a>b>c
					ans+=tmpa;++numa;
					mema[numa]=tmpa-tmpb;
				}else{//a>b<=c
					if(tmpa>tmpc){
						ans+=tmpa;++numa;
						mema[numa]=tmpa-tmpc;
					}else{//a>b<=c,a<=c
						ans+=tmpc;++numc;
						memc[numc]=tmpc-tmpa;
					}
				}
			}else{//a<=b
				if(tmpb>tmpc){//a<=b>c
					if(tmpa>tmpc){
						ans+=tmpb;++numb;
						memb[numb]=tmpb-tmpa;
					}else{
						ans+=tmpb;++numb;
						memb[numb]=tmpb-tmpc;
					}
				}else{//a<b<=c
					ans+=tmpc;++numc;
					memc[numc]=tmpc-tmpb;
				}
			}
		}
		if(numa>(n>>1)){
			sort(mema+1,mema+1+numa);
			for(int i=1;i<=numa-(n>>1);++i){
				ans-=mema[i];
			}
		}else if(numb>(n>>1)){
			sort(memb+1,memb+1+numb);
			for(int i=1;i<=numb-(n>>1);++i){
				ans-=memb[i];
			}
		}else if(numc>(n>>1)){
			sort(memc+1,memc+1+numc);
			for(int i=1;i<=numc-(n>>1);++i){
				ans-=memc[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
