#include<bits/stdc++.h>
using namespace std;
int a[5500];
int ans;


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int da=0;
	for(int i=1;i<=n;i++){
		da=max(a[i],da);
	}
	if(n==3&&a[1]+a[2]+a[3]>da*2){
		ans++;
	}
	
	cout<<ans%998244353;
	
	return 0;
}
