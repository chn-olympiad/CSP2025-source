#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		int k=0;
		for(int i=1;i<=n;i++) k+=a[i];
		if(k>a[n]*2) cout<<1;
		else cout<<0;
		return 0;
	}
	if(a[n]==1){
		int ans=0,q=1;
		for(int i=3;i<=n;i++){
			q=1;
			for(int j=1;j<=i;j++) q=q*(n-j+1);
			ans+=q;
		}
		cout<<ans;
		return 0;
	}
	cout<<n+1;
	return 0;
}
