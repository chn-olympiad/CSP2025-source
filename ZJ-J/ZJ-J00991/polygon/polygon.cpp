#include <bits/stdc++.h>
using namespace std;
int n;
int side[5010];
int flag;
int J(long long x){
	if(x==0 || x==1) return 1;
	return x*J(x-1);
}
int C(long long a,long long b){
	return J(a)/J(a-b)/J(b);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>side[i];
		if(side[i]!=1) flag=1;
	}
	if(n==3){
		if(side[1]+side[2]+side[3]>2*max(max(side[1],side[2]),side[3])) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==4){
		if(side[1]+side[2]+side[3]+side[4]>2*max(max(max(side[1],side[2]),side[3])side[4]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==5){
		if(side[1]+side[2]+side[3]+side[4]+side[5]>2*max(max(max(max(side[1],side[2]),side[3]),side[5]),side[4]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(!flag){
		long long ans=0;
		for(int i=0;i<=n-3;i++){
			ans+=C(n,i);
			//if(ans>=998244353) ans%=998244353;
		}
		cout<<ans%998244353;
	}
	return 0;
}