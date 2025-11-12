#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum1=0,sum2=0,sum3=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		sum1+=a[i];
		sum2=max(a[i],a[i+1]);
		if(sum1>=sum2*2){
			sum3++;
		}
	}
	cout<<sum3;
	return 0;
} 
