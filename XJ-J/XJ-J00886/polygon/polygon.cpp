#include<bits/stdc++.h>
using namespace std;

int main() {

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	long long arr[n+1];
	for(long long i=0; i<n; i++) {
		cin>>arr[i];
	}
	sort(arr,arr+5);
	for(long long i=0; i<=n; i++) {
		for(long long j=i+1; j<=n; j++) {
			for(long long m=j+1; m<=n; m++) {
				for(long long h=m+1;h<=n;h++){
					for(long long g=h+1;g<=n;g++){
					if(i!=j&&j!=m&&i!=m){
					if(arr[i]+arr[j]>arr[m]){
			    	cnt++;
				}
			}
				if(i!=j&&j!=m&&i!=m&&i!=h&&j!=h&&m!=h){
					if(arr[i]+arr[j]+arr[m]>arr[h]){
			    	cnt++;
						
				}
				}
					if(i!=j&&j!=m&&i!=m&&i!=h&&j!=h&&m!=h&&i!=g&&j!=g&&m!=g&&h!=g){
					if(arr[i]+arr[j]+arr[m]+arr[h]>arr[g]){
			    	cnt++;
				}		
				}
				}
			}
		}
	}
}
cout<<cnt;
	return 0;
}
