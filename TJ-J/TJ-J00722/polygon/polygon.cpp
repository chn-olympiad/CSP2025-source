#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		long long num=0;
		for(int i=n-3;i>=1;i--){
			for(int j=1;j<=n-3;j++){
				num+=i*j;
			}
		}
		cout<<num;
	}
	return 0;
}
