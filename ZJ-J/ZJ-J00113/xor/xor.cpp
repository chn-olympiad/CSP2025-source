#include<bits/stdc++.h>
using namespace std;
int n,k,num,ans,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
//	v=k;
//	while(k){
//		m++;
//		x[m]=k%2;
//		k/=2;
//	}
//	t=m;
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		if(num==1) sum++;
		if(num==k){
			ans++;
			continue;
		}
//		m=0;	
//		while(num){
//			m++;
//			y=num%2;
//			if(y==1){
//				sum[m]++;
//				a[m][sum[m]]=i;	
//			}
//			num/=2;
//		}
//		t=max(m,t);
	} 
	if(k==0){
		ans+=sum/2;
		printf("%d",ans);
		return 0;
	}
	printf("%d",ans);
	return 0;
//	for(int j=1;j<=t;j++){
//		if(x[j]==0){
//			for(int i=1;i<=sum[j];i=i+2){
//				printf("%d %d\n",a[j][i+1],a[j][i]);
//				if((i+1)>sum[j]) break;
//				f[a[j][i]]=a[j][i+1];
//				for(int l=a[j][i]+1;l<a[j][i+1];l++) f[l]=a[j][i+1];
//				f[a[j][i+1]]=a[j][i];
//			}
//		}
//	}
//	for(int i=n;i>=1;i--){
//		if(f[i]!=i){
//			i=f[i]-1;
//			ans++;
//		}
//	}
}