#include<bits/stdc++.h>
using namespace std;
long long n,maxn,sum,sum2,t,k,cnt,l=1,arr[5005];
long long C(long long x,long long y){
	long long ans=1;
	y=min(y,x-y);
	for(long long i=x;i>=x-y+1;i--) ans=ans*i;
	for(long long i=y;i>=1;i--) ans=ans/i;
	return ans%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
		sum+=arr[i];
		maxn=max(maxn,arr[i]);
	}
	if(n==3){
		if(sum>maxn*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	sort(arr+1,arr+1+n);
	t=n;
	for(long long i=n;i>=3;i--){
		sum-=arr[i];
		sum2=sum;
		if(sum>arr[i]){
			cnt=(cnt+C(n,i))%998244353;
			continue;
		}
		while(l<=n-i+1){
			t=n;
			while(sum2<=arr[t] and t>=l+i-1) t--;
			if(t<l+i-1){
				sum2=sum2-arr[l]+arr[l+i-1];
				l++;
				k=n;
				while(k>=l+i-1 and sum2<=arr[k]) k--;
				cnt=(cnt+k-l-i+2)%998244353;
			}
			else{
				cnt=(cnt+t-l-i+2)%998244353;
				l++;
			}
			sum2=sum2-arr[l]+arr[l+i-1];
			l++;
		}
	}
	cout<<cnt%998244353;
	return 0;
}
