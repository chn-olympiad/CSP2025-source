#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,sum[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a[1]>>a[2]>>a[3];
		if(a[1]+a[2]<=a[3]||a[2]+a[3]<=a[1]||a[3]+a[1]<=a[2]) printf("0");
		else printf("1");
	}else if(n<=5000){
		for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
		for(int i=1;i<1<<n;i++){
			int j=i,sum=0,Max=0,num=0;
			for(int k=1;k<=n;k++){
				if(j%2==1) Max=max(Max,a[k]),sum+=a[k],num++;
				j/=2;
			}
			if(num<3) continue;
			if(sum>2*Max) ans++,ans%=998244353;
		}
		printf("%d\n",ans);
	}
	return 0;
}
