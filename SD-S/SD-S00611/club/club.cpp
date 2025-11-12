#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
long long ans=0;
struct node{
	int de1,de2,de3;
	int cha;
}e[N];
struct nd{
	int data,chazhi;
	bool operator<(const nd& a) const{
		return chazhi>a.chazhi;
	}
};
priority_queue<nd> dq1,dq2,dq3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		while(!dq1.empty()) dq1.pop();
		while(!dq2.empty()) dq2.pop();
		while(!dq3.empty()) dq3.pop();
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&e[i].de1,&e[i].de2,&e[i].de3);
			int minx=min(e[i].de1,min(e[i].de2,e[i].de3));
			if(e[i].de1==minx){
				e[i].cha=abs(e[i].de2-e[i].de3);
			}
			else if(e[i].de2==minx){
				e[i].cha=abs(e[i].de1-e[i].de3);
			}
			else if(e[i].de3==minx){
				e[i].cha=abs(e[i].de2-e[i].de1);
			}
		}
		for(int i=1;i<=n;i++){
			int maxx=max(e[i].de1,max(e[i].de2,e[i].de3));
			if(e[i].de1==maxx){
				if(dq1.size()==(n/2)){
					int tmp=dq1.top().chazhi,da=dq1.top().data;
					if(tmp<e[i].cha){
						ans-=da;
						dq1.pop();
						dq1.push({e[i].de1,e[i].cha});
						ans+=e[i].de1;
						ans+=(da-tmp);
					}
					else ans+=e[i].de1-e[i].cha;
					continue;
				}
				dq1.push({e[i].de1,e[i].cha});
				ans+=e[i].de1;
			}
			else if(e[i].de2==maxx){
				if(dq2.size()==(n/2)){
					int tmp=dq2.top().chazhi,da=dq2.top().data;
					if(tmp<e[i].cha){
						ans-=da;
						dq2.pop();
						dq2.push({e[i].de2,e[i].cha});
						ans+=e[i].de2;
						ans+=(da-tmp);
					}
					else ans+=e[i].de2-e[i].cha;
					continue;
				}
				dq2.push({e[i].de2,e[i].cha});
				ans+=e[i].de2;
			}
			else if(e[i].de3==maxx){
				if(dq3.size()==(n/2)){
					int tmp=dq3.top().chazhi,da=dq3.top().data;
					if(tmp<e[i].cha){
						ans-=da;
						dq3.pop();
						dq3.push({e[i].de3,e[i].cha});
						ans+=e[i].de3;
						ans+=(da-tmp);
					}
					else ans+=e[i].de3-e[i].cha;
					continue;
				}
				dq3.push({e[i].de3,e[i].cha});
				ans+=e[i].de3;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
