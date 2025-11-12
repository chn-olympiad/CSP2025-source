#include<bits/stdc++.h>
using namespace std;
int n,x;
int a[1000005];
const int ans=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cout<<log(n*n);
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		x=a[1]+a[2]+a[3];
		int p=max(a[1],a[2]);
		int q=a[3];
		int m=max(p,q);
		if(x>m*2) cout<<1;
		else cout<<0;
	}else{
		cout<<1;
	}
	return 0;
}
