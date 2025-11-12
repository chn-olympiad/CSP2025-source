#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[5009],b[5009];
int c[5009][5009],l[5009][5009];
long long dfs(long long i,long long t,long long k){
	if(i==0)return 0;
	if(c[i][k]==t && l[i][k]!=0){
		if(t+a[i]>k){
			return 1+b[i];
		}
		else{
			return b[i];
		}
	}
	else if(t+a[i]>k){
		b[i]=dfs(i-1,t+a[i],k)+dfs(i-1,t,k);
		b[i]=b[i]%mod;
		c[i][k]=t;
		l[i][k]=1;
		return 1+b[i];
	}
	else{
		b[i]=dfs(i-1,t+a[i],k)+dfs(i-1,t,k);
		b[i]=b[i]%mod;
		c[i][k]=t;
		l[i][k]=1;
		return b[i];
	}
	if(i==0)return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		sum=sum+dfs(i-1,0,a[i]);
		sum=sum%mod;
	}
	cout<<sum;
	return 0;
}
