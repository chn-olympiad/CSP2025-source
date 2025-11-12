#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+3];
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]+a[i+1]>a[i+2]&&a[i+2]-a[i+1]<a[i]){
			sum++;
		}
		if(a[i]+a[i+i]+a[i+i+i]>a[i+i+i+i+i]&&a[i+i+i+i]+a[i+i+i+i+i]>a[i]+a[i+i+i]){
			sum++;
		}
	}
	cout<<sum+1;
	return 0;
}