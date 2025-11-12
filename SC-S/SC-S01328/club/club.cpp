#include<bits/stdc++.h>
using namespace std;
const int N=210;
int t,n,a[N],b[N],c[N],f[N][N][N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		if(n>200){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int x1=0;x1<=min(n/2,i);x1++){
				for(int x2=0;x2<=min(n/2,i-x1);x2++){
					f[i][x1][x2]=0;
					int x3=i-x1-x2;
					if(x3>n/2){
						continue;
					}
					if(x1){
						f[i][x1][x2]=max(f[i][x1][x2],f[i-1][x1-1][x2]+a[i]);
					}
					if(x2){
						f[i][x1][x2]=max(f[i][x1][x2],f[i-1][x1][x2-1]+b[i]);
					}
					if(x3){
						f[i][x1][x2]=max(f[i][x1][x2],f[i-1][x1][x2]+c[i]);
					}
					if(i==n){
						ans=max(ans,f[i][x1][x2]);
					} 
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}