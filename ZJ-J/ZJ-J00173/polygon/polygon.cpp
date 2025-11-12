#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
int maxx[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<"1";
			return 0;
		}
		cout<<"0";
		return 0;
	} 
	ans=0;
	for(int i=1;i<=n-2;i++){
		ans+=i*(n-1-i);
		ans%=998244353;
	}
	cout<<ans;
	//cout<<n-2;
	
	/*for(int i=1;i<=n;i++){
		maxx[i]=2*a[i];
	}
	for(int i=3;i<=n;i++){
		p(i,maxx[i]);
	}
	cout<<ans%998244353;*/
}
