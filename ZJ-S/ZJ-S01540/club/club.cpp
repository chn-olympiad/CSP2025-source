#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int id,num;
};
node x[N],y[N],z[N];
long long ans=0;
int t,n,a[N][5],vis[N],cntx,cnty,cntz,kcnt[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);
		ans=0;
		cntx=0,cnty=0,cntz=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",a[i]+1,a[i]+2,a[i]+3);
			if(a[i][1]>=a[i][2] and a[i][1]>=a[i][3]){				
				x[++cntx].num=a[i][1],x[cntx].id=i;
				ans+=a[i][1];
			}else if(a[i][2]>=a[i][1] and a[i][2]>=a[i][3]){
				y[++cnty].num=a[i][2],y[cnty].id=i;
				ans+=a[i][2];
			}else if(a[i][3]>=a[i][1] and a[i][3]>=a[i][2]){
				z[++cntz].num=a[i][3],z[cntz].id=i;
				ans+=a[i][3];
			}
		}	
		if(cntx>n/2){
			for(int i=1;i<=cntx;i++){
				kcnt[i]=x[i].num-max(a[x[i].id][2],a[x[i].id][3]);
			}sort(kcnt+1,kcnt+cntx+1);
			for(int i=1;i<=cntx-n/2;i++){
				ans-=kcnt[i];
			}
		}
		else if(cnty>n/2){
			for(int i=1;i<=cnty;i++){
				kcnt[i]=y[i].num-max(a[y[i].id][1],a[y[i].id][3]);
			}sort(kcnt+1,kcnt+cnty+1);
			for(int i=1;i<=cnty-n/2;i++){
				ans-=kcnt[i];
			}
		}
		else if(cntz>n/2){
			for(int i=1;i<=cntz;i++){
				kcnt[i]=z[i].num-max(a[z[i].id][1],a[z[i].id][2]);
			}sort(kcnt+1,kcnt+cntz+1);
			for(int i=1;i<=cntz-n/2;i++){
				ans-=kcnt[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}