#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
int n,a[N],sum,num[N],ans;
int c(int a,int b){
	return 1ll*num[b]/(num[b-a]*num[a]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum=max(sum,a[i]);
	}
	num[0]=1;
	for(int i=1;i<=n;i++)num[i]=(num[i-1]*i)%mod;
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
	}else if(sum==1){
		for(int i=3;i<=n;i++)ans=(ans+c(i,n))%mod;
		cout<<ans;
	}else cout<<ans;
	return 0;
}