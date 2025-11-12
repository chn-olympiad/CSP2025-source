#include<bits/stdc++.h>
using namespace std;

dfs(long long n){
	if(n==1){
		return 1;
	}
	return (2*dfs(n-1)+1)%998244353;
}
long long n,a[5010],flag;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	sort(a,a+n);
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[0]+a[1]<=a[2]){
			cout<<0;
			return 0;
		}else if(a[0]+a[1]>a[2]){
			cout<<1;
			return 0;
		}
	}
	if(flag==0){
		cout<<(dfs(n)-n-n*(n-1)/2)%998244353;
		return 0;
	}
	return 0;
}



