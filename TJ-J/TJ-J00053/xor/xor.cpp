#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[230],b[230];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
	cin>>a[i];
	a[i]=a[i-1]+b[i];
	a[i]=1;
}
for(int i=1;i<=k;i++){
	cout<<a[n]-a[k-1];
}
cout<<k;
	return 0;
}
