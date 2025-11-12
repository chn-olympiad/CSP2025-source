#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][4],cnt[4],maxn[100001],cz[100001],ans;
struct node{
	int v,id;
}cz1[100001];
bool cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int k=0;
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<=2;i++){
			cnt[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				scanf("%d",&a[i][j]);
			}
			if(a[i][0]>=a[i][2]&&a[i][0]>=a[i][1]){
				maxn[i]=0;
				cnt[0]++;
				cz[i]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				maxn[i]=1;
				cnt[1]++;
				cz[i]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
			}else{
				maxn[i]=2;
				cnt[2]++;
				cz[i]=min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
			}
		}
		for(int i=1;i<=n;i++){
			if(cnt[maxn[i]]<=n/2){
				ans+=a[i][maxn[i]];
			}else{
				k++;
				cz1[k].v=cz[i];
				cz1[k].id=i;
			}
		}
		sort(cz1+1,cz1+k+1,cmp);
		for(int i=1;i<=k;i++){
			int id=cz1[i].id;
			if(i<=n/2){
				ans+=a[id][maxn[id]];
			}else{
				ans+=(a[id][maxn[id]]-cz1[i].v);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
