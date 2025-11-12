#include<bits/stdc++.h>
using namespace std;
long long a[10000],b[10000],n,sum,maxn;
long long C(long long n,long long m){
	long long sum=1;
	for(int i=n;i>n-m;i--) sum=sum*i%998244353;
	for(int i=1;i<=m;i++) sum/=i;
	return sum;
}
void dfs(long long x,long long k){
	if(x>n){
		long long t1=0,t2=0;
		for(int i=1;i<=k;i++) t1+=a[b[i]],t2=max(t2,a[b[i]]);
		if(k>2&&t1>2*t2) sum=(sum+1)%998244353;
		return;
	}
	b[k+1]=x;
	dfs(x+1,k+1);
	b[k+1]=0;
	dfs(x+1,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		for(int i=3;i<=n;i++) sum=(sum+C(n,i))%998244353;
		cout<<sum;
	}
	else{
		dfs(1,0);
		cout<<sum;
	}
	return 0;
}
