#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,rty[10],ans,s,g;
struct P{
	int h[10],mx,c,ok;
}a[100005];
bool cmp(P x,P y){
	return x.c<y.c;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		s=0;
		g=0;
		memset(a,0,sizeof a);
		memset(rty,0,sizeof rty);
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i].h[j]);
				if(a[i].h[j]>a[i].mx){
					a[i].mx=a[i].h[j];
					a[i].ok=j;
				}
			}
			ans+=a[i].mx;
			rty[a[i].ok]++;
			a[i].c=100000;
			for(int j=1;j<=3;j++){
				if(j==a[i].ok)continue;
				int u=a[i].mx-a[i].h[j];
				a[i].c=min(a[i].c,u);
			}
		}
		if(rty[1]<=n/2&&rty[2]<=n/2&&rty[3]<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		int hh=max(rty[1],max(rty[2],rty[3]));
		if(rty[1]==hh)s=1;
		else if(rty[2]==hh)s=2;
		else s=3;
		g=hh-n/2;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].ok!=s)continue;
			ans-=a[i].c;
			g--;
			if(g==0)break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
