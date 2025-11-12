#include<bits/stdc++.h>
using namespace std;
int n,a[1000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3&&a[3]*2<=a[1]+a[2]+a[3]) cout<<1;
	else if(n==3&&a[3]*2>a[1]+a[2]+a[3]) cout<<0;
	else cout<<n-2;
	return 0;
}