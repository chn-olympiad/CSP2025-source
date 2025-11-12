#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,i,j,k,m,t,cnt1=0,cnt2=0,cnt3=0,ans=0;
LL a[1000005][4];
LL val[1000005][4];
priority_queue<LL,vector<LL>,greater<LL> > h;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		while(!h.empty()) h.pop();
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		  scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		cnt1=cnt2=cnt3=ans=0;
		for(i=1;i<=n;i++){
			if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3]))){
				val[i][1]=1,cnt1++;
				if(a[i][2]>=a[i][3]) val[i][2]=2;
				else val[i][2]=3;
			}
			else if(a[i][2]==max(a[i][1],max(a[i][2],a[i][3]))){
				val[i][1]=2,cnt2++;
				if(a[i][1]>=a[i][3]) val[i][2]=1;
				else val[i][2]=3;
			}
			else{
				val[i][1]=3,cnt3++;
				if(a[i][1]>=a[i][2]) val[i][2]=1;
				else val[i][2]=2;
			}
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(cnt1>n/2){
			for(i=1;i<=n;i++)
			  if(val[i][1]==1) h.push(a[i][val[i][1]]-a[i][val[i][2]]);
			while(!h.empty() && cnt1>n/2) ans-=h.top(),h.pop(),cnt1--;
		}
		if(cnt2>n/2){
			for(i=1;i<=n;i++)
			  if(val[i][1]==2) h.push(a[i][val[i][1]]-a[i][val[i][2]]);
			while(!h.empty() && cnt2>n/2) ans-=h.top(),h.pop(),cnt2--;
		}
		if(cnt3>n/2){
			for(i=1;i<=n;i++)
			  if(val[i][1]==3) h.push(a[i][val[i][1]]-a[i][val[i][2]]);
			while(!h.empty() && cnt3>n/2) ans-=h.top(),h.pop(),cnt3--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//homura is the cutest!
//Ren5Jie4Di4Ling5%
