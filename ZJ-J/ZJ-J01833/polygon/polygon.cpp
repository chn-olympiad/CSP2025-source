#include<bits/stdc++.h>
using namespace std;
int a[505000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mx=a[n];
	a[n]=0,n--;
	if(mx==1){
		long long ans=1;
		for(int i=1;i<=n;i++)ans=ans*2%988244353;
		cout<<ans-n-1;
		return 0;
	}
	if(n==2){
		if(a[1]+a[2]>mx)cout<<1;
		else cout<<0;
	}
	return 0;
}
