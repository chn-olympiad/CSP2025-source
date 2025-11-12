#include<bits/stdc++.h>
using namespace std;
long long n,a[5000],maxx=0,add=0,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		add+=a[i];
		maxx=max(maxx,a[i])
	}
	if(n==3){
		if(add>2*maxx)
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	if(maxx==1){
		for(int i=1;i<=n-2;i++){
			ans+=i;
			ans%=998244353;
		}
	}
	return 0;
}

