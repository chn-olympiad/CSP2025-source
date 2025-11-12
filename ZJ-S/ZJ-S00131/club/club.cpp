#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e5+6;
int t,n;
LL ans;
int b[maxn],cnt[4];

struct Ren{
	int num,d1,d2,d3;
}ren[maxn];

bool cmp1(Ren a,Ren b){
	return a.d1>b.d1;
}

bool cmp2(Ren a,Ren b){
	return a.d2>b.d2;
}

bool cmp3(Ren a,Ren b){
	return a.d3>b.d3;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(b,0,sizeof(b));
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++){
			ren[i].num=i;
			scanf("%d%d%d",&ren[i].d1,&ren[i].d2,&ren[i].d3);
		}
		sort(ren+1,ren+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(b[ren[i].num]<ren[i].d1&&cnt[1]<=n/2){
				b[ren[i].num]=ren[i].d1;
				cnt[1]++;
			} 
		}
		sort(ren+1,ren+1+n,cmp2);
		for(int i=1;i<=n;i++){
			if(b[ren[i].num]<ren[i].d2&&cnt[2]<=n/2){
				b[ren[i].num]=ren[i].d2;
				cnt[2]++;
			}
		}
		sort(ren+1,ren+1+n,cmp3);
		for(int i=1;i<=n;i++){
			if(b[ren[i].num]<ren[i].d3&&cnt[3]<=n/2){
				b[ren[i].num]=ren[i].d3;
				cnt[3]++;
			}
		}
		for(int i=1;i<=n;i++) ans+=b[i];
		printf("%lld\n",ans);
	} 
	return 0;
}
