#include<bits/stdc++.h>
using namespace std;
int n,k,arr[100000005],sum = 0;
int main(){
	 freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	} 
	int u = k;
	u*=k;
	sort(arr+1,arr+n+1);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			sum+=i+j;
		}
	}
	if(arr[n] == arr[1]){
		cout<<1;
		return 0;
	}
	cout<<arr[n]-arr[1];




	return 0;
}

