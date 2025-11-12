#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,cnt[4],ans;
struct node{
	int cha;
	int ax[4];
	int maxn;
}a[N];
bool cmp(node x,node y){
	return x.cha<y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].ax[1],&a[i].ax[2],&a[i].ax[3]);
			int a1=a[i].ax[1],a2=a[i].ax[2],a3=a[i].ax[3];
			if(a1>=a2 && a1>=a3){
				a[i].cha=a1-max(a2,a3);
				cnt[1]++;
				ans+=a1;
				a[i].maxn=1;
			} 
			else if(a2>=a1 && a2>=a3){
				a[i].cha=a2-max(a1,a3);
				cnt[2]++;
				ans+=a2;
				a[i].maxn=2;
			} 
			else{
				a[i].cha=a3-max(a1,a2);
				cnt[3]++;
				ans+=a3;
				a[i].maxn=3;
			}
		}
		if(max(cnt[1],max(cnt[2],cnt[3]))<=n/2){
			printf("%d\n",ans);
			continue;
		}
		sort(a+1,a+n+1,cmp);
		int flag;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2) flag=i;
		}
		for(int i=1;i<=n;i++){
			if(a[i].maxn!=flag) continue;
			ans-=a[i].cha;
			cnt[flag]--;
			if(cnt[flag]<=n/2) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}