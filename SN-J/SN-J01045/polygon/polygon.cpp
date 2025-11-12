#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n==3){
		int sum=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		if(a[n]*2<sum){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(n==4){
		int sum1=0;
		sort(a+1,a+n+1);
		if (a[1]+a[2]+a[3]>a[3]*2){
			sum1+=1;
		}
		if (a[1]+a[2]+a[4]>a[4]*2){
			sum1+=1;
		}
		if (a[1]+a[3]+a[4]>a[4]*2){
			sum1+=1;
		}
		if (a[2]+a[3]+a[4]>a[4]*2){
			sum1+=1;
		}
		if (a[1]+a[2]+a[3]+a[4]>a[4]*2){
			sum1+=1;
		}
		cout<<sum1;
	}
	return 0;
}
