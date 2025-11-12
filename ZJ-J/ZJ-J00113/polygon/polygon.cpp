#include<bits/stdc++.h>
using namespace std;
int n,l,r,f=1,a[5005],sum[5005];
long long cnt;
long long way(int x){
	long long num=1,numm=1,sum=0;
	for(int t=2;t<=x;t++){
		num=1,numm=1;
		for(int i=x;i>=x+1-t;i--) num*=(long long)i;
		for(int i=t;i>=2;i--) numm*=(long long)i;
		sum+=num/numm;
		sum%=998244353;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	f=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) f=0;
	}
	if(f==1){
		cnt=way(n);
		printf("%lld",cnt);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=3;i--){
		r=1;
		if(a[i]>=sum[i-1]) continue;
		if(i==3){
			cnt++;
			continue;
		}
		for(int j=i-1;j>=2;j--){
			if(j==i-1) l=j;
			if(sum[j]<=a[i]){
				r=j;
				break;
			}
		}
		cnt+=(way(l)-way(r)-r)%998244353;
	}
	printf("%lld",cnt);
	return 0;
}