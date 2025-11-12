#include<bits/stdc++.h>
using namespace std;
struct ss{
	int a,b,c;
}mp[200005];
int vis[200005];
int huana[200005],huanb[200005],huanc[200005];
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	int n;
	int na,nb,nc;
	while(T--){
		ans=0;
		na=0,nb=0,nc=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&mp[i].a,&mp[i].b,&mp[i].c);
			if(mp[i].a>=mp[i].b&&mp[i].a>=mp[i].c) na++,ans+=mp[i].a,vis[i]=1,huana[na]=min(mp[i].a-mp[i].b,mp[i].a-mp[i].c);
			else if(mp[i].b>=mp[i].a&&mp[i].b>=mp[i].c) nb++,ans+=mp[i].b,vis[i]=2,huanb[nb]=min(mp[i].b-mp[i].a,mp[i].b-mp[i].c);
			else if(mp[i].c>=mp[i].a&&mp[i].c>=mp[i].b) nc++,ans+=mp[i].c,vis[i]=3,huanc[nc]=min(mp[i].c-mp[i].a,mp[i].c-mp[i].b);;
		}
		sort(huana+1,huana+1+na);
		sort(huanb+1,huanb+1+nb);
		sort(huanc+1,huanc+1+nc);
		if(na>n/2){
			for(int i=1;i<=na-n/2;i++){
				ans-=huana[i];
			}
			printf("%lld\n",ans);
		}else if(nb>n/2){
			for(int i=1;i<=nb-n/2;i++){
				ans-=huanb[i];
			}
			printf("%lld\n",ans);
		}else if(nc>n/2){
			for(int i=1;i<=nc-n/2;i++){
				ans-=huanc[i];
			}
			printf("%lld\n",ans);
		}else{
			printf("%lld\n",ans);
		}
	}
	return 0;
}