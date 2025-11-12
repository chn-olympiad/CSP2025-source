#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n,a[100001][4],x[4],c[100001],ans=0,top=0;
		for(int i=1;i<=3;i++)
			x[i]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++){
			int ma=0;
			for(int j=1;j<=3;j++)
				ma=max(ma,a[i][j]);
			ans+=ma;
			for(int j=1;j<=3;j++)
				if(a[i][j]==ma){
					x[j]++;
					break;
				}
		}
		for(int k=1;k<=3;k++)
			if(x[k]>n/2){
				for(int i=1;i<=n;i++){
					if(k==1&&a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
						if(a[i][2]>=a[i][3])
							c[++top]=a[i][1]-a[i][2];
						else
							c[++top]=a[i][1]-a[i][3];
					}
					else if(k==2&&a[i][2]>=a[i][1]&&a[i][1]>=a[i][3]){
						if(a[i][1]>=a[i][3])
							c[++top]=a[i][2]-a[i][1];
						else
							c[++top]=a[i][2]-a[i][3];
					}
					else if(k==3&&a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
						if(a[i][1]>=a[i][2])
							c[++top]=a[i][3]-a[i][1];
						else
							c[++top]=a[i][3]-a[i][2];
					}
				}
			}
		sort(c+1,c+top+1);
		for(int i=1;i<=3;i++)
			if(x[i]>n/2)
				for(int j=1;j<=x[i]-n/2;j++)
					ans-=c[j];
		printf("%d\n",ans);
	}
}
