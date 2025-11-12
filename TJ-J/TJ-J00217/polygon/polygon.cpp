#include<bits/stdc++.h>
using namespace std;
long long n,a[5000],cnt,num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num+=a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=n;i>=3;i--){
		long long sum=num;
		for(int j=0;j<=n-3;j++){
			sum-=a[j];
			if(sum>a[i]*2) cnt=(cnt+1)%998244353;
			else break;
		}
		num-a[i];
	}
	cout<<cnt;
	return 0;
}
