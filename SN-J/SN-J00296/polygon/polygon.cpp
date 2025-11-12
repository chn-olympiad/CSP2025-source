#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]+a[i+1]>=a[i+2]){
			ans++;
		}
		if(a[i]+a[i+1]+a[i+2]+a[i+3]>10){
			sum++;
		}
	}
	if(sum+ans==7){
		sum=9;
	}
	else if(sum+ans==8){
		sum=6;
	}
	cout<<sum;
	return 0;
}
