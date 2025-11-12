#include<bits/stdc++.h>
using namespace std;
int n,k,s=0,a[500001],a1=0,a0=0,ans1=0,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int t=1;t<=n;t++){
		scanf("%d",&a[t]);
		if(a[t]!=0&&a[t]!=1) s=1;
		if(a[t]==1) a1++;
		if(a[t]==0) a0++;
		if(a[t]==k){
			ans++;
		}
	}
	if(s==0){
		if(k!=1&&k!=0) printf("0");
		else{
			if(k==1){
				printf("%d",a1);
			}
			if(k==0){
				ans1+=a0;
				for(int t=1;t<=n;t++){
					if(a[t]==1&&a[t+1]==1){
						ans1++;
						a[t+1]=-1;
					}
				}
				printf("%d",ans1);
			}
		}
	}
	else{
		printf("%d",ans);
	}
	return 0;
}
