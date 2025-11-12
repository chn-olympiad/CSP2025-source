#include<bits/stdc++.h>

using namespace std;
long long n,k,a[500010],b[500010],ans=0,Sum=0,sum_xor_num=0,sum,er[25],T=0;

int sum_xor(long long x,long long y){
	sum_xor_num=0;
	T=0;
	while(x!=0 || y!=0){
		T++;
		er[T]=0;
		if(x%2 != y%2){
			er[T]=1;
		}
		x/=2;
		y/=2;
	}
	for(int i=T;i>=1;i--){
		sum_xor_num*=2;
		sum_xor_num+=er[i];
	}
	return sum_xor_num;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)b[i]=-1;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=n;i++){
		sum=a[i];
		if(a[i]==k){
			b[i]=i;
			continue;
		}
		if(a[i]==0)continue;
		for(long long j=i-1;j>=1;j--){
			if(b[j]!=-1)break;
			if(a[j]==0)continue;
			sum=sum_xor(sum,a[j]);
			if(sum==k){
				b[i]=j;
				break;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		if(b[i]!=-1){
			if(b[i]>Sum){
				ans++;
				Sum=i;
			}
		}
	}
	cout<<ans;
	return 0;
}

