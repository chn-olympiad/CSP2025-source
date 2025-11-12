#include<bits/stdc++.h>
using namespace std;
int n,a[3];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a[0]>>a[1]>>a[2];
	sort(a,a+n);
	if((a[0]+a[1]<=a[2])||(a[2]+a[1]>=a[0])||(a[2]+a[0]>=a[1])) cout<<0;
	else cout<<1;
	return 0;
}
