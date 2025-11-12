#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,maxi,ans=0;
int main(){
	cin>>n;
	for (int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for (int i = 1;i<=n;i++){
		sum+=a[i];
		if (a[i]>maxi)maxi = a[i];
	}
	if (maxi*2<sum) ans++;
	cout<<ans;
	return 0;
}
