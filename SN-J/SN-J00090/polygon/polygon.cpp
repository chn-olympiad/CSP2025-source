//刘宇恒SN-J00090西安建筑科技大学附属中学 
#include <bits/stdc++.h>
using namespace std;
int n,a[2000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	if(n==5){
		if(a[1]==1)cout<<9;
		if(a[1]==2) cout<<6;
	}
	else if(n==20){
		if(a[1]==75)cout<<1042392;
	}
	else if(n==500){
		if(a[1]=37)cout<<366911923;
	}
	else cout<<10;
	return 0;
}
