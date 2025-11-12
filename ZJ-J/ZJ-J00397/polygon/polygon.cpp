#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[100001],s,ma;
const int mod=998244353; 
int zh(int x){
	int sum1,sum2,i,j,sum=0;
	for(i=3;i<=x;i++){
		sum1=1;sum2=1;
		for(j=x;j>=x-i+1;j--)sum1=sum1*(j%mod);
		for(j=i;j>=1;j--)sum2=sum2*(j%mod);
		sum=(sum+(sum1/sum2)%mod)%mod;
	}
	return sum;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	if(n<3)cout<<0;
	else if(n==3){
		ma=max(max(a[1],a[2]),a[3]);
		s=a[1]+a[2]+a[3];
		if(s>2*ma)cout<<1;
		else cout<<0;
	}
	else{
		for(i=1;i<=n;i++)
			ma=max(ma,a[i]);
		if(ma==1){
			cout<<zh(n)%mod;
		}
	}
}
/*
#Shang4Shan3Ruo6Shui4
*/
