#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],b[100005],c[4],d[100005],ans,tp;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		ans=tp=0;
		memset(c,0,sizeof c);
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++)scanf("%d",&a[j][k]);
		}
		for(int j=1;j<=n;j++){
			if(max(max(a[j][1],a[j][2]),a[j][3])==a[j][1]){
				c[1]++;
				b[j]=1;
			}
			else if(max(max(a[j][1],a[j][2]),a[j][3])==a[j][2]){
				c[2]++;
				b[j]=2;
			}
			else{
				c[3]++;
				b[j]=3;
			}
		}
		for(int j=1;j<=n;j++)ans+=a[j][b[j]];
		if(max(max(c[1],c[2]),c[3])<=n/2)printf("%d\n",ans);
		else if(c[1]>n/2){
			for(int j=1;j<=n;j++){
				if(b[j]==1)d[++tp]=a[j][1]-max(a[j][2],a[j][3]);
			}
			sort(d+1,d+tp+1);
			for(int j=1;j<=c[1]-n/2;j++)ans-=d[j];
			printf("%d\n",ans);
		}
		else if(c[2]>n/2){
			for(int j=1;j<=n;j++){
				if(b[j]==2)d[++tp]=a[j][2]-max(a[j][1],a[j][3]);
			}
			sort(d+1,d+tp+1);
			for(int j=1;j<=c[2]-n/2;j++)ans-=d[j];
			printf("%d\n",ans);
		}
		else{
			for(int j=1;j<=n;j++){
				if(b[j]==3)d[++tp]=a[j][3]-max(a[j][1],a[j][2]);
			}
			sort(d+1,d+tp+1);
			for(int j=1;j<=c[3]-n/2;j++)ans-=d[j];
			printf("%d\n",ans);
		}
	}
	return 0;
}
