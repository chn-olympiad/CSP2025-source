#include<bits/stdc++.h>
using namespace std;
int n,arr[1000005],sum = 0;
int main(){
	 freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
		for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			sum+=i+j;
		}
	}
	if(arr[2] == arr[1]){
		cout<<1;
		return 0;
	}
	cout<<arr[2]-arr[1];



	return 0;
}

