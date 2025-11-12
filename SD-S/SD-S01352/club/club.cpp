#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,cnt[5];
struct person{
	int d[5];
}p[100007];
struct perso{
	int pr,id,pr1;
}club[5][100007];
bool cmp(perso cl1,perso cl2){
	return cl1.pr-cl1.pr1<cl2.pr-cl2.pr1;
}
void t1_solve(){
	cnt[1]=cnt[2]=cnt[3]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&p[i].d[1],&p[i].d[2],&p[i].d[3]);
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		int maxn=1;
		for(int j=2;j<=3;j++){
			if(p[i].d[j]>=p[i].d[maxn]){
				maxn=j;
			}
		}
		club[maxn][++cnt[maxn]].id=i;
		club[maxn][cnt[maxn]].pr=p[i].d[maxn];
		ans+=p[i].d[maxn];
		int maxn1=0;
		for(int j=1;j<=3;j++){
			if(j==maxn) continue;
			if(p[i].d[j]>=p[i].d[maxn1]){
				maxn1=j;
			}
		}
		club[maxn][cnt[maxn]].pr1=p[i].d[maxn1];
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]>n/2){
			sort(club[i]+1,club[i]+1+cnt[i],cmp);
			for(int j=1;j<=cnt[i]-n/2;j++){
				ans=ans-(club[i][j].pr-club[i][j].pr1);
			}
		}
	}
	printf("%lld\n",ans);
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) t1_solve();
	return 0;
}
