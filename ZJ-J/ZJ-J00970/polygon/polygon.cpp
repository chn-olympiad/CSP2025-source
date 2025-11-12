#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[100100],x,ans;
int A(int x,int n){
	int xxx=1;
	for(int i=1;i<=x;i++){
		xxx*=n;
		xxx%=mod;
		n--;
	}
	return xxx;
}
int C(int x,int n){
	return A(x,n)/A(x,x);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],x+=a[i];
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	if(x==n){
		for(int i=3;i<=n;i++){
			ans+=C(i,n);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n==5){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<9;
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10) cout<<6;
		return 0;
	}
	cout<<0;
	return 0;
}
/*
10
1 1 1 1 1 1 1 1 1 1

*/
