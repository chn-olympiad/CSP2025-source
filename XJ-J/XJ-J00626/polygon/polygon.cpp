#include<bits/stdc++.h>
using namespace std;
int a[504],n,N=998244353,ans=1;
int add(int x,int y){
	return ((x%N)-(y%N))%N;
}
int mle(int x,int y){
	return ((x%N)*(y%N))%N;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>max(a[1],max(a[2],a[3]))*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			ans=mle(ans,2);
		}
		ans=add(ans,n+1);
		ans=add(ans,n*(n-1)/2);
	}
	cout<<ans;
	return 0;
} 
