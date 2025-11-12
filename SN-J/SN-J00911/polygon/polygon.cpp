#include<bits/stdc++.h> 
using namespace std;
long long n,a[5010],sum=0,mx=0,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(n==3||n>3){
		if(sum>(mx*2)){
			if(mx==1){
				for(int j=1;j<=n-2;j++){
					ans+=j;
				}
				cout<<ans%998244353;
			}else{
				cout<<1%998244353;
			}
		}else{
			cout<<0%998244353;
		}
	}else{
		cout<<0%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
