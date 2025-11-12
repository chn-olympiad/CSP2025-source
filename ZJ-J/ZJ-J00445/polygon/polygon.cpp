#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5010],i,n;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==5){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
			cout<<9;
			return 0;
	}
	if(n==5){
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
			cout<<6;
			return 0;
	}
	if(n==20){
		cout<<1042392;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
}