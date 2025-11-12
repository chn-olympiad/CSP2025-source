#include <bits/stdc++.h>
using namespace std;
int arr[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num=1;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
		if(arr[i]>arr[1]){
			num++;
		}
	}
	int a=num/n;
	int b=num%n;
	if(b==0){
		if(a%2==0){
			cout<<a<<" 1";
		}else{
			cout<<a<<" "<<n;
		}
	}else{
		if(a%2==0){
			cout<<a+1<<" "<<b;
		}else{
			cout<<a+1<<" "<<n+1-b;
		}
	}
	return 0;
}