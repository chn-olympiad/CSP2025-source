#include<bits/stdc++.h>
using namespace std;
int n,a[5009],maax=-1;
long long sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maax=max(maax,a[i]);
		sum+=a[i];
	}
	if(n==3){
		if(sum>maax*2) cout<<1;
		else cout<<0;
	}
	else{
		int b=n-2;
		cout<<(b+1)*b/2;
	}
	return 0;
}
