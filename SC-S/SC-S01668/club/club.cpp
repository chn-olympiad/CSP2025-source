#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
int n,t,vis[MAXN],cnt[5],ans;
struct stu{
	int aa[5],num;
	stu(){
		memset(aa,0,sizeof(aa));
		num=0;
	}
}q1[MAXN],q2[MAXN],q3[MAXN];
bool cmp1(stu x,stu y){
	if(x.aa[2]+x.aa[3]==y.aa[2]+y.aa[3])return x.aa[1]>y.aa[1];
	else return x.aa[2]+x.aa[3]<y.aa[2]+y.aa[3];
}
bool cmp2(stu x,stu y){
	if(x.aa[1]+x.aa[3]==y.aa[1]+y.aa[3])return x.aa[2]>y.aa[2];
	else return x.aa[1]+x.aa[3]<y.aa[1]+y.aa[3];
}
bool cmp3(stu x,stu y){
	if(x.aa[1]+x.aa[2]==y.aa[1]+y.aa[2])return x.aa[3]>y.aa[3];
	else return x.aa[1]+x.aa[2]<y.aa[1]+y.aa[2];
}
bool cmp(stu x,stu y,int r1,int r2){
	if(x.aa[1]+x.aa[2]+x.aa[3]-x.aa[r1]==y.aa[1]+y.aa[2]+y.aa[3]-y.aa[r2])return x.aa[r1]<y.aa[r2];
	else return x.aa[1]+x.aa[2]+x.aa[3]-x.aa[r1]>y.aa[1]+y.aa[2]+y.aa[3]-y.aa[r2];
}
queue<stu>qq[5];
void init(){
	ans=0;
	for(int i=1;i<=n;i++){
		q1[i].aa[1]=q1[i].aa[2]=q1[i].aa[3]=q1[i].num=0;
	}
	for(int i=1;i<=n;i++){
		q2[i].aa[1]=q2[i].aa[2]=q2[i].aa[3]=q2[i].num=0;
	}
	for(int i=1;i<=n;i++){
		q3[i].aa[1]=q3[i].aa[2]=q3[i].aa[3]=q3[i].num=0;
	}
	for(int i=1;i<=n;i++)vis[i]=0;
	memset(cnt,0,sizeof(cnt));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&q1[i].aa[1],&q1[i].aa[2],&q1[i].aa[3]);
			q1[i].num=i;
			q2[i]=q1[i],q3[i]=q1[i];
		}
		sort(q1+1,q1+n+1,cmp1);
		sort(q2+1,q2+n+1,cmp2);
		sort(q3+1,q3+n+1,cmp3);
		for(int i=1;i<=n;i++){
			qq[1].push(q1[i]);
			qq[2].push(q2[i]);
			qq[3].push(q3[i]);
		}
		while(qq[1].size()||qq[2].size()||qq[3].size()){
			int x[5],maxn=-1,maxc=0;
			memset(x,0,sizeof(x));
			for(int i=1;i<=3;i++){
				while(qq[i].size()&&vis[qq[i].front().num])qq[i].pop();
				x[i]=qq[i].size()?qq[i].front().aa[i]:0;
				if((x[i]>maxn||(x[i]==maxn&&cnt[i]<cnt[maxc]))&&cnt[i]<n/2)maxn=x[i],maxc=i;
			}
		//	cout<<qq[1].front().aa[1]<<" "<<qq[2].front().aa[2]<<" "<<qq[3].front().aa[3]<<endl;
		//	cout<<maxc<<endl;
			if(qq[maxc].empty())continue;
			vis[qq[maxc].front().num]=1;
			ans+=qq[maxc].front().aa[maxc];
			qq[maxc].pop();
			cnt[maxc]++;
		}
		printf("%d\n",ans);
	}
	return 0;
}