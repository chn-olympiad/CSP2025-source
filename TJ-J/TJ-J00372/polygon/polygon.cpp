#include <bits/stdc++.h>
using namespace std;
int arr[10000005];
int brr[10000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>arr[i];
	} 
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		brr[i]=brr[i-1]+arr[i];
	}
	int ans=0;
	for(int j=2;j<=n;j++){
		for(int i=1;i<=n-j+1;i++){
			if((brr[i+j]-brr[i-1])>arr[i+j]*2){
				ans++;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
