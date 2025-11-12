#include<stdio.h>
#include<string.h>
#include<algorithm>
typedef long long ll;
const int N=1e5+5;
struct stu{
	ll a,b,c,id;
};
namespace{
	ll t,n,cnt[4],ans;
	stu a[N];
}
ll min(ll a,ll b){return a<b? a:b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(cnt,0,sizeof cnt);
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c) ans+=a[i].a,a[i].id=1,cnt[1]++;
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c) ans+=a[i].b,a[i].id=2,cnt[2]++;
			else if(a[i].c>=a[i].b&&a[i].c>=a[i].a) ans+=a[i].c,a[i].id=3,cnt[3]++;
		}
		if(cnt[1]>n/2){
			std::sort(a+1,a+1+n,[](const stu&x,const stu&y){return min(x.a-x.b,x.a-x.c)<min(y.a-y.b,y.a-y.c);});
			for(int i=1;i<=n;i++){
				if(a[i].id!=1) continue;
				if(a[i].a-a[i].b<a[i].a-a[i].c) cnt[1]--,cnt[2]++,ans-=(a[i].a-a[i].b);
				else cnt[1]--,cnt[3]++,ans-=(a[i].a-a[i].c);
				if(cnt[1]<=n/2) break;
			}
		}else if(cnt[2]>n/2){
			std::sort(a+1,a+1+n,[](const stu&x,const stu&y){return min(x.b-x.a,x.b-x.c)<min(y.b-y.a,y.b-y.c);});
			for(int i=1;i<=n;i++){
				if(a[i].id!=2) continue;
				if(a[i].b-a[i].a<a[i].b-a[i].c) cnt[2]--,cnt[1]++,ans-=(a[i].b-a[i].a);
				else cnt[2]--,cnt[3]++,ans-=(a[i].b-a[i].c);
				if(cnt[2]<=n/2) break;
			}
		}else if(cnt[3]>n/2){
			std::sort(a+1,a+1+n,[](const stu&x,const stu&y){return min(x.c-x.a,x.c-x.b)<min(y.c-y.a,y.c-y.b);});
			for(int i=1;i<=n;i++){
				if(a[i].id!=3) continue;
				if(a[i].c-a[i].a<a[i].c-a[i].b) cnt[3]--,cnt[1]++,ans-=(a[i].c-a[i].a);
				else cnt[3]--,cnt[2]++,ans-=(a[i].c-a[i].b);
				if(cnt[3]<=n/2) break;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}