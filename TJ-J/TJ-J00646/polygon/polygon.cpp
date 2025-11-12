#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,a[5005];
long long f(long long x){
	long long sum=n;
	for(long long i=1;i<x;i++){
		sum=(sum*(long long)(n-i))%MOD;
	}
	long long summ=x;
	for(long long i=1;i<x;i++){
		summ=(summ*i)%MOD;
	}
	sum=(sum/summ)%MOD;
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0<<"\n";
		return 0;
	}else if(n==3){
		cout<<1<<"\n";
		return 0;
	}else{
		long long ans=0;
		for(long long i=3;i<=n;i++){
			ans+=f(i);
			ans%=MOD;
		}
		cout<<ans<<"\n";
		return 0;
	}
	return 0;
}
//rp++
