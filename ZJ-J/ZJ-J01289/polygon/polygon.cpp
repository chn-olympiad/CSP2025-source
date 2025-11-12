#include<bits/stdc++.h>
using namespace std;
int n,ans=1,a[5005],b;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			b=1;
		}
	}
	if(!b){
		for(int i=1;i<=n;i++){
			ans=(ans*2)%998244353;
		}
		ans=(ans-n-(n-1)*n/2-1)%998244353;
		cout<<ans;
	}
	else{
		if(n==3){
			if(2*max(max(a[1],a[2]),a[3])<(a[1]+a[2]+a[3])){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
	return 0;
}
