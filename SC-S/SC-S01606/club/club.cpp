#include<bits/stdc++.h>
using namespace std;
const int N=1e5+12;
int t,n,n2,r[3];
long long d[3],ans;
struct no{long long m;int b;}a1[N],a2[N];
void dfs(int x,long long sum){
	if(x==n+1){ans=max(ans,sum);return ;}
	if(r[a1[x].b]!=n2) r[a1[x].b]++,dfs(x+1,sum+a1[x].m),r[a1[x].b]--;
	if(r[a2[x].b]!=n2) r[a2[x].b]++,dfs(x+1,sum+a2[x].m),r[a2[x].b]--;
	return ;
}
bool cmp(no x1,no x2){return x1.m>x2.m;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		n2=n/2;ans=0;r[1]=0;r[2]=0;r[3]=0;
		int d2=1,d3=1;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&d[1],&d[2],&d[3]);
			if(d[2]) d2=0;if(d[3]) d3=0;
			if(d[1]>=d[2]&&d[2]>=d[3]) a1[i].m=d[1],a1[i].b=1,a2[i].m=d[2],a2[i].b=2;
			if(d[2]>=d[1]&&d[1]>=d[3]) a1[i].m=d[2],a1[i].b=2,a2[i].m=d[1],a2[i].b=1;
			if(d[3]>=d[1]&&d[1]>=d[2]) a1[i].m=d[3],a1[i].b=3,a2[i].m=d[1],a2[i].b=1;
			if(d[1]>=d[3]&&d[3]>=d[2]) a1[i].m=d[1],a1[i].b=1,a2[i].m=d[3],a2[i].b=3;
			if(d[2]>=d[3]&&d[3]>=d[1]) a1[i].m=d[2],a1[i].b=2,a2[i].m=d[3],a2[i].b=3;
			if(d[3]>=d[2]&&d[2]>=d[1]) a1[i].m=d[3],a1[i].b=3,a2[i].m=d[2],a2[i].b=2;
		}
		if(d2*d3){
			sort(a1+1,a1+1+n,cmp);
			for(int i=n;i>n/2;i--) ans+=a1[i].m;
			printf("%lld\n",ans);
			continue;
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}