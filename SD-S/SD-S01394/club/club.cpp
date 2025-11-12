#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[114514][3];
int maxn[114514];
int lmaxn[114514];
int dis[114514];
int pu[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		pu[0]=pu[1]=pu[2]=0;
		memset(maxn,0,sizeof(maxn));
		memset(lmaxn,0,sizeof(lmaxn));
		memset(dis,0,sizeof(dis));
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				maxn[i]=0;
				if(a[i][1]>=a[i][2])lmaxn[i]=1;
				else lmaxn[i]=2;
			}
			if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				maxn[i]=1;
				if(a[i][0]>=a[i][2])lmaxn[i]=0;
				else lmaxn[i]=2;
			}
			if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]){
				maxn[i]=2;
				if(a[i][1]>=a[i][0])lmaxn[i]=1;
				else lmaxn[i]=0;
			}
			dis[i]=a[i][maxn[i]]-a[i][lmaxn[i]];
			pu[maxn[i]]++;
			ans+=a[i][maxn[i]];
		}
		int k=-1,cha=0;
		for(int i=0;i<=2;i++){
			if(pu[i]>n/2){
				k=i;
				cha=pu[i]-n/2;
			}
		}
		if(k!=-1){
			for(int i=1;i<=n;i++){
				if(maxn[i]!=k)
					dis[i]=1145141;
			}
			sort(dis+1,dis+n+1);
			for(int i=1;i<=cha;i++){
				ans-=dis[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
