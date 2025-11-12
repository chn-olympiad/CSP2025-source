#include<bits/stdc++.h>
using namespace std;
long long arr[5010];
long long n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	if(n<=3){
		if(arr[1]+arr[2]<=arr[3]){
			cout<<0;
		}else{
			cout<<1;
		}
		return 0;
	}
	cout<<0;
	return 0;
}
