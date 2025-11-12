#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],sum,ans,res,maxs;
bool flag;
int qpow(int a,int b){
	int ans=1;
	while(b>0){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(flag==0){
		cout<<qpow(2,n)-1-n-n*(n-1)/2;
		return 0;
	}
	for(int i=0;i<(1<<n);i++){
		sum=ans=maxs=0;
		for(int j=0;j<n;j++)
			if((i>>j)&1) sum++,ans+=a[j+1],maxs=max(maxs,a[j+1]);
		if(sum<3) continue;
		if(ans>2*maxs) res=(res+1)%mod;
	}
	cout<<res;
	return 0;
}
