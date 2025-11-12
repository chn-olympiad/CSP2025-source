#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
long long t,n,cnt[10],f[10],ans;
struct jjq{
	long long c[10],num,val; 
}m1[maxn],m2[maxn],m3[maxn];
bool cmp(jjq a,jjq b){
	return a.num>b.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while (t--){
		scanf("%lld",&n);
		for (int i=1;i<=n;i++){
			int t1,t2,t3;
			scanf("%lld%lld%lld",&t1,&t2,&t3);
			long long maxs=max(t1,max(t2,t3));
			if (maxs==t1){
				m1[++cnt[1]].c[1]=t1;
				m1[cnt[1]].c[2]=t2;
				m1[cnt[1]].c[3]=t3;
				m1[cnt[1]].num=i;
			}
			else if (maxs==t2){
				m2[++cnt[2]].c[1]=t1;
				m2[cnt[2]].c[2]=t2;
				m2[cnt[2]].c[3]=t3;
			}
			else {
				m3[++cnt[3]].c[1]=t1;
				m3[cnt[3]].c[2]=t2;
				m3[cnt[3]].c[3]=t3;
			}
			ans+=maxs;
		}
		//printf("%d ",ans);
		if(cnt[1]>n/2)f[1]=1;
		else if(cnt[2]>n/2)f[2]=1;
		else if(cnt[3]>n/2)f[3]=1;
		if (f[1]){
			for (int i=1;i<=cnt[1];i++){
				if (m1[i].c[2]-m1[i].c[1]<m1[i].c[3]-m1[i].c[1])m1[i].val=3,m1[i].num=m1[i].c[3]-m1[i].c[1];
				else m1[i].val=2,m1[i].num=m1[i].c[2]-m1[i].c[1];
			//	printf("%d %d\n",m1[i].c[2]-m1[i].c[1],m1[i].c[2]-m1[i].c[1]);
			}
			sort(m1+1,m1+cnt[1]+1,cmp);
			for (int i=1;cnt[1]>(n/2);i++){
				ans+=m1[i].num;
				//printf("%d ",m1[i].num);
				cnt[1]--;
			}
		}
		else if(f[2]){
			for (int i=1;i<=cnt[2];i++){
				if (m2[i].c[1]-m2[i].c[2]<m2[i].c[3]-m2[i].c[2])m2[i].val=3,m2[i].num=m2[i].c[3]-m2[i].c[2];
				else m2[i].val=1,m2[i].num=m2[i].c[1]-m2[i].c[2];
				//printf("%d %d\n",m2[i].c[2]-m2[i].c[1],m2[i].c[2]-m2[i].c[1]);
			}
			sort(m2+1,m2+cnt[2]+1,cmp);
			for (int i=1;cnt[2]>(n/2);i++){
				ans+=m2[i].num;
			//	printf("%d %d\n",m2[1].num,m2[3].num);
				cnt[2]--;
			}
		}
		else if (f[3]){
			for (int i=1;i<=cnt[3];i++){
				if (m3[i].c[1]-m3[i].c[3]<m3[i].c[2]-m3[i].c[3])m3[i].val=2,m3[i].num=m3[i].c[2]-m3[i].c[3];
				else m3[i].val=1,m3[i].num=m3[i].c[1]-m3[i].c[3];
			//	printf("%d %d\n",m3[i].c[2]-m3[i].c[1],m3[i].c[2]-m2[i].c[1]);
			}
			sort(m3+1,m3+cnt[3]+1,cmp);
			for (int i=1;cnt[3]>(n/2);i++){
				ans+=m3[i].num;
				//printf("%d ",m3[i].num);
				cnt[3]--;
			}
		}/**/
		printf("%lld\n",ans);
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=f[1]=f[2]=f[3]=0;
	}
	return 0;
} 
/*
447450
417649
473417
443896
484387



*/
