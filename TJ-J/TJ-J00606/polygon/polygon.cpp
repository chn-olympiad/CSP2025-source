#include <iostream>
#include <algorithm>
#include <cstdio> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n;cin>>n;int a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}int sum=0,sum1=0;
	for(int k=0;k<n;k++){
		int maxx=k;
		for(int i=k;i<n;i++){
			if(a[maxx]<a[i]){
				maxx=i;
			}
		}
		int temp=a[k];
		a[k]=a[maxx];a[maxx]=temp;
		//cout<<a[k];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=i;k<=j;k++){
				sum1+=a[k];
			}
			if(sum1>(2*a[i])){
				sum+=1;
			}
		}
	}
	cout<<sum%998244353;return 0;
}
