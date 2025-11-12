#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N=2e5+10;
int t1,t2,t3,sum[4],a[N][4],ans,T,n;
struct Node{int val,id;}b[N];
bool cmp(Node x,Node y){return x.val>y.val;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		t1=1;t2=2;t3=3;sum[1]=sum[2]=sum[3]=0;ans=0;
		for (int i=1;i<=n;i++){
			if (a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) sum[1]++,ans+=a[i][1];
			else if (a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) sum[2]++,ans+=a[i][2];
			else if (a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) sum[3]++,ans+=a[i][3];
		}
		if (sum[1]>=sum[2]&&sum[1]>=sum[3]) t1=1,t2=(sum[2]>=sum[3]?2:3),t3=(sum[2]>=sum[3]?3:2);
		else if (sum[2]>=sum[1]&&sum[2]>=sum[3]) t1=2,t2=(sum[1]>=sum[3]?1:3),t3=(sum[1]>=sum[3]?3:1);
		else if (sum[3]>=sum[1]&&sum[3]>=sum[2]) t1=3,t2=(sum[1]>=sum[2]?1:2),t3=(sum[1]>=sum[2]?2:1);
		if (sum[t1]<=n/2) printf("%d\n",ans);
		else{
			int tot=0;
			for (int i=1;i<=n;i++)
				if (a[i][t1]>=a[i][t2]&&a[i][t1]>=a[i][t3]) b[++tot].val=max(a[i][t2]-a[i][t1],a[i][t3]-a[i][t1]),b[tot].id=i;
			sort(b+1,b+tot+1,cmp);int now=1;
			while (sum[t1]>n/2){
				int h=b[now++].id;
				if (a[h][t2]>=a[h][t3]) ans+=a[h][t2]-a[h][t1],sum[t1]--;
				else ans+=a[h][t3]-a[h][t1],sum[t1]--;
			}
			printf("%d\n",ans);
			
		}
	}
	return 0;
}
