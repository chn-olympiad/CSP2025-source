#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct Node{
	int pos,a1,a2,a3;
}mb[N],mb1[N],mb2[N],mb3[N];
int T,n,ans;
int jn[N];
int cnt1,cnt2,cnt3;
bool cmp1(Node x,Node y){
	return x.a1>y.a1;
}
bool cmp2(Node x,Node y){
	return x.a2>y.a2;
}
bool cmp3(Node x,Node y){
	return x.a3>y.a3;
}
void dfs(int cur,int sum){
	if(cur==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(cnt1<(n/2)){
		cnt1++;
		dfs(cur+1,sum+mb[cur].a1);
		cnt1--;
	}
	if(cnt2<(n/2)){
		cnt2++;
		dfs(cur+1,sum+mb[cur].a2);
		cnt2--;
	}
	if(cnt3<(n/2)){
		cnt3++;
		dfs(cur+1,sum+mb[cur].a3);
		cnt3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		cnt1=cnt2=cnt3=0;
		bool flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&mb1[i].a1,&mb1[i].a2,&mb1[i].a3);
			mb[i].a1=mb3[i].a1=mb2[i].a1=mb1[i].a1;
			mb[i].a2=mb3[i].a2=mb2[i].a2=mb1[i].a2;
			mb[i].a3=mb3[i].a3=mb2[i].a3=mb1[i].a3;
			mb[i].pos=mb3[i].pos=mb2[i].pos=mb1[i].pos=i;
			if(mb[i].a2!=0) flag1=1;
			if(mb[i].a3!=0) flag2=1;
		}
		if(n<=16){
			dfs(1,0);
			printf("%d\n",ans);
			continue;
		}
		if(!flag1){
			sort(mb1+1,mb1+1+n,cmp1);
			for(int i=1;i<=n/2;i++) ans+=mb1[i].a1;
			printf("%d\n",ans);
			continue;
		}
		sort(mb1+1,mb1+1+n,cmp1);
		sort(mb2+1,mb2+1+n,cmp2);
		sort(mb3+1,mb3+1+n,cmp3);
//		printf("mb1:\n");
//		for(int i=1;i<=n;i++){
//			printf("i %d a1 %d a2 %d a3 %d\n",mb1[i].pos,mb1[i].a1,mb1[i].a2,mb1[i].a3);
//		}
//		printf("mb2:\n");
//		for(int i=1;i<=n;i++){
//			printf("i %d a1 %d a2 %d a3 %d\n",mb2[i].pos,mb2[i].a1,mb2[i].a2,mb2[i].a3);
//		}
//		printf("mb3:\n");
//		for(int i=1;i<=n;i++){
//			printf("i %d a1 %d a2 %d a3 %d\n",mb3[i].pos,mb3[i].a1,mb3[i].a2,mb3[i].a3);
//		}
		for(int i=1;i<=n/2;i++) jn[mb1[i].pos]=1;
		//cnt2=0;
		for(int i=1;i<=n&&cnt2<n/2;i++){
			if(jn[mb2[i].pos]==1&&mb2[i].a2>mb2[i].a1){
				cnt2++;
				jn[mb2[i].pos]=2;
			}
			else if(jn[mb2[i].pos]==0){
				cnt2++;
				jn[mb2[i].pos]=2;
			}
		}
		//cnt3=0;
		for(int i=1;i<=n&&cnt3<n/2;i++){
			if(jn[mb3[i].pos]==1&&mb3[i].a3>mb3[i].a1){
				cnt3++;
				jn[mb3[i].pos]=3;
			}else if(jn[mb3[i].pos]==2&&mb3[i].a3>mb3[i].a2){
				cnt3++;
				jn[mb3[i].pos]=3;
			}else if(jn[mb3[i].pos]==0){
				cnt3++;
				jn[mb3[i].pos]=3;
			}
		}
		for(int i=1;i<=n;i++){
			//printf("%d ",jn[i]);
			if(jn[i]==1) ans+=mb[i].a1;
			else if(jn[i]==2) ans+=mb[i].a2;
			else ans+=mb[i].a3;
			jn[i]=0;
		}
		//printf("\n");
		printf("%d\n",ans);
	}
	return 0;
}
