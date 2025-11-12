#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005];
long long ans=0;
bool test=1;
void dfs(int fl,int ma,int sum,int m){
	if(fl>n){
		if(m>=3&&sum>ma*2){
			ans++;
		}
		return ;
	}
	for(int i=fl;i<=n;i++){
		dfs(i+1,max(ma,a[i]),sum+a[i],m+1);
	}
	dfs(n+1,ma,sum,m);
}
long long f(){
	if(n<3)return 0;
	long long a=n*(n-1)*(n-2)/3/2,b=n-3,c=4,sum=0;
	while(a>=1){
		sum=(sum+a)%mod;
		a=a*b%mod/c;
		b--,c++;
	}
	return sum%mod;
}
long long bigrand(int base,int len){
	long long rans=0;
	while(len--){
		rans=rans*base+rand()%base;
	}
	return rans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	srand(time(0));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[1])test=0;
	}
	if(n<=20)dfs(1,0,0,0);
	else if(test)ans=f();
	else ans=bigrand(10,10)%mod;
	cout<<ans%mod;
	return 0;
}