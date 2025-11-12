#include<bits/stdc++.h>
using namespace std;
int n,a[5],mmax;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	mmax=max(a[1],max(a[2],a[3]));
	if(a[1]+a[2]+a[3]>mmax*2) cout<<1;
	else cout<<0;
	return 0;
}
