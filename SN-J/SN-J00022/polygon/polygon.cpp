#include<bits/stdc++.h>
using namespace std;
int a[1005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,mx=-1e9;cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		int ans=0;
		for(int i=1;i<=n-2;i++){
			int sum=0;
			for(int j=1;j<=i;j++){
				sum+=j;
			}
			ans+=(n-1-i)*sum;
		}
		cout<<ans;
	}
	else{
		if(n==3){
			if(a[0]+a[1]+a[2]>mx*2){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}
}
