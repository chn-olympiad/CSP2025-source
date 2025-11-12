#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005][5],ma,mi,tot,ton[5],q[100005],ans,k;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ton[1]=ton[2]=ton[3]=0;ans=0;k=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			ma=max(a[i][1],max(a[i][2],a[i][3]));
			mi=min(a[i][1],min(a[i][2],a[i][3]));
			tot=a[i][1]+a[i][2]+a[i][3];
			for(int j=1;j<=3;j++){if(a[i][j]==ma){ton[j]++;ans+=ma;q[i]=j;break;}}
			a[i][1]=ma;a[i][2]=tot-ma-mi;
		}
		if(ton[1]>n/2){k=1;}
		if(ton[2]>n/2){k=2;}
		if(ton[3]>n/2){k=3;}
		if(k){
			tot=0;
			for(int i=1;i<=n;i++){if(q[i]==k){q[++tot]=a[i][1]-a[i][2];}}
			sort(q+1,q+tot+1);
			for(int i=1;i<=tot-n/2;i++){ans-=q[i];}
		}
		printf("%d\n",ans);
	}
	return 0;
}