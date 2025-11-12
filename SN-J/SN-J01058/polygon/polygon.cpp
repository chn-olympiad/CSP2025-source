#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;//n表示木棍的数量 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	if (n==3){
		if (a[1]+a[2]>a[3]) {
			cout<< 1%998244353;
		}
		else cout<<0%998244353;
	}
	else if (n==4){
		if (a[1]+a[2]+a[3]>a[4]) ans++;
		if (a[1]+a[3]>a[4]) ans++;
		if (a[1]+a[2]>a[4]) ans++;
		if (a[2]+a[3]>a[4]) ans++;
		cout<<ans%998244353;
	}
	else if (n==5){
		if (a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5]) ans++;
		if (a[1]+a[2]+a[3]+a[4]>2*a[5]) ans++;
		if (a[1]+a[2]+a[3]+a[5]>2*a[5]) ans++;
		if (a[1]+a[2]+a[4]+a[5]>2*a[5]) ans++;
		if (a[1]+a[3]+a[4]+a[5]>2*a[5]) ans++;
		if (a[2]+a[3]+a[4]+a[5]>2*a[5]) ans++;
		if (a[1]+a[2]+a[3]>2*a[5]) ans++;
		if (a[1]+a[2]+a[4]>2*a[5]) ans++;
		if (a[1]+a[2]+a[5]>2*a[5]) ans++;
		if (a[2]+a[3]+a[4]>2*a[5]) ans++;
		if (a[2]+a[3]+a[5]>2*a[5]) ans++;
		if (a[3]+a[4]+a[5]>2*a[5]) ans++;

		cout<<ans%998244353;
	}
	else if (n==6){
		if (a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*a[6]) ans++;
		if (a[1]+a[2]+a[3]+a[4]+a[5]>2*a[6]) ans++;
		if (a[1]+a[2]+a[3]+a[4]+a[6]>2*a[6]) ans++;
		if (a[1]+a[2]+a[3]+a[5]+a[6]>2*a[6]) ans++;
		if (a[1]+a[2]+a[4]+a[5]+a[6]>2*a[6]) ans++;
		if (a[1]+a[5]+a[3]+a[4]+a[6]>2*a[6]) ans++;
		if (a[5]+a[2]+a[3]+a[5]+a[6]>2*a[6]) ans++;
		
		if (a[1]+a[2]+a[3]+a[4]>2*a[6]) ans++;
		if (a[1]+a[2]+a[3]+a[5]>2*a[6]) ans++;
		if (a[1]+a[2]+a[3]+a[6]>2*a[6]) ans++;
		if (a[1]+a[2]+a[4]+a[5]>2*a[6]) ans++;
		if (a[1]+a[2]+a[5]+a[6]>2*a[6]) ans++;
		if (a[1]+a[3]+a[4]+a[5]>2*a[6]) ans++;
		if (a[1]+a[3]+a[4]+a[6]>2*a[6]) ans++;
		if (a[1]+a[3]+a[5]+a[6]>2*a[6]) ans++;
		if (a[2]+a[3]+a[4]+a[5]>2*a[6]) ans++;
		if (a[2]+a[3]+a[4]+a[6]>2*a[6]) ans++;
		if (a[2]+a[3]+a[5]+a[6]>2*a[6]) ans++;
		if (a[2]+a[4]+a[5]+a[6]>2*a[6]) ans++;
		if (a[3]+a[4]+a[5]+a[6]>2*a[6]) ans++;
		
		if (a[1]+a[2]+a[3]>2*a[6]) ans++;
		if (a[1]+a[2]+a[4]>2*a[6]) ans++;
		if (a[1]+a[2]+a[5]>2*a[6]) ans++;
		if (a[1]+a[2]+a[6]>2*a[6]) ans++;
		if (a[1]+a[3]+a[4]>2*a[6]) ans++;
		if (a[1]+a[3]+a[5]>2*a[6]) ans++;
		if (a[1]+a[3]+a[6]>2*a[6]) ans++;
		if (a[1]+a[4]+a[5]>2*a[6]) ans++;
		if (a[1]+a[4]+a[6]>2*a[6]) ans++;
		if (a[1]+a[5]+a[6]>2*a[6]) ans++;
		if (a[2]+a[3]+a[4]>2*a[6]) ans++;
		if (a[2]+a[3]+a[5]>2*a[6]) ans++;
		if (a[2]+a[3]+a[6]>2*a[6]) ans++;
		if (a[2]+a[4]+a[5]>2*a[6]) ans++;
		if (a[2]+a[4]+a[6]>2*a[6]) ans++;
		if (a[2]+a[5]+a[6]>2*a[6]) ans++;
		if (a[3]+a[4]+a[5]>2*a[6]) ans++;
		if (a[3]+a[4]+a[6]>2*a[6]) ans++;
		if (a[3]+a[5]+a[6]>2*a[6]) ans++;
		if (a[4]+a[5]+a[6]>2*a[6]) ans++;
		

		cout<<ans%998244353;
	}
	
	return 0;//随缘这一块 
} 
