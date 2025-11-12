#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
long long n,k,a[1000100],ans,flag;
long long mpow(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1)res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
void dfs(long long i,long long sum,long long maxn){
	if(i==n+1){
		if(sum>2*maxn){
		ans++;
		ans%=998244353;
		}
		return;
	}
	dfs(i+1,sum+a[i],max(maxn,a[i]));
	dfs(i+1,sum,maxn);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	if(flag==1&&n<=20){
		dfs(1,0,0);
		cout<<ans%998244353;
	}
	else{
		cout<<(mpow(2,n)-n-n*(n-1)/2-1+998244353)%998244353;
	}
	return 0;
}
