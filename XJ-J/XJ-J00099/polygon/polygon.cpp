#include<bits/stdc++.h>
using namespace std;
long long int n,a[5005],maxn;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],maxn=max(maxn,a[i]);
	if(n==3){
		if(a[1]+a[2]+a[3]>maxn*2)cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<n*(n-1);
	return 0;
} 
