#include<bits/stdc++.h>
using namespace std;
long long n,i,a[1000010],ans,sum;
const int Mod=998244353;
void sc(long long t,long long k,long long maxx,long long sum){
	if(t==n){
		if(k>=3&&sum>maxx*2){
			ans++;
			ans%=Mod;
		}
		return ;
	}
	sc(t+1,k+1,a[t+1],sum+a[t+1]);
	sc(t+1,k,maxx,sum);
}
int pl(long long x){
	long long i,sum;
	sum=1;
	for(i=n;i>=n-x+1;i--) sum=(sum*i)%Mod;
	for(i=x;i>=1;i--) sum=sum/i;
	return sum%Mod;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=25){
		sc(0,0,0,0);
		cout<<ans;	
	}
	else{
		sum=1;
		for(i=3;i<=n;i++)
			ans=(ans+pl(i))%Mod;
		cout<<ans;
	}
	return 0;
}
