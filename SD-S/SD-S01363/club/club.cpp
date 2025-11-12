#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int t,n;
bool vis[100005];
struct node{
	int x[3],id,maxid1,maxid2;
}a[100005];
int getid(node &A){
	if(A.x[0]>=A.x[1] && A.x[0]>=A.x[2])return 0;
	if(A.x[1]>=A.x[2] && A.x[1]>=A.x[0])return 1;
	return 2;
}
int getid2(node &A){
	if((A.x[0]>=A.x[1] && A.x[0]<=A.x[2]) || (A.x[0]<=A.x[1] && A.x[0]>=A.x[2]))return 0;
	if((A.x[1]>=A.x[2] && A.x[1]<=A.x[0]) || (A.x[1]<=A.x[2] && A.x[1]>=A.x[0]))return 1;
	return 2;
}
bool cmp1(node &A,node &B){
	return A.x[A.maxid1]-A.x[A.maxid2]>B.x[B.maxid1]-B.x[B.maxid2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof vis);
		int cnt[3]={0},ans=0; 
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x[0],&a[i].x[1],&a[i].x[2]);
			a[i].id=i;
			a[i].maxid1=getid(a[i]);
			a[i].maxid2=getid2(a[i]);
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			int id=a[i].maxid1;
			if(cnt[id]<n/2){
				vis[a[i].id]=1;
				cnt[id]++;
				ans+=a[i].x[id];
			}
		}
//		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(vis[a[i].id])continue;
			int id=a[i].maxid2;
			cnt[id]++;
			ans+=a[i].x[id];
		}
		printf("%d\n",ans);
	}
	return 0;
}
