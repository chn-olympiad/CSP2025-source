#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int ans=0;
int xun(int ci,int sum,int mx,int fi){
	if(ci==3){
		int mxx=mx;
		int smm=sum;
		for(int i=fi;i<=n;i++){
  		mxx=mx;smm=sum;
			for(int j=i+1;j<=n;j++){
				mxx=mx;smm=sum;
				for(int k=j+1;k<=n;k++){
					mxx=mx;smm=sum;
					mxx=max(mxx,a[k]);
					smm=a[i]+a[j]+a[k]+smm;
					if(smm>2*mxx){
						ans++;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
/*
else{
	for(int i=fi;i<=n;i++){
		int b=xun(ci-1,sum+a[i],max(mx,a[i]),i+1);
	}
	return 0;
}
*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=3;i<=n;i++){
		xun(i,0,0,1);
	}
	printf("%d",ans);
	return 0;
}