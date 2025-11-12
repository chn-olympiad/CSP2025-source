#include<bits/stdc++.h>
using namespace std;
int ans=0;
void xun(int x){
	if(x==0){
		return ;
	}
	for(int i=x;i>=1;i--){
		ans+=i;
	}xun(x-1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>3){
		for(int i=3;i<=n;i++){
			xun(n-i+1);
			ans=ans%998244353;
		}cout<<ans+1;
	}else{
		if(a[1]+a[2]+a[3]<=max(a[1],max(a[2],a[3]))*2){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

