#include<bits/stdc++.h>
using namespace std;
int arr[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	int sum=1;
	for(int i=2;i<=n*m;i++){
		if(arr[1]<arr[i]){
			sum+=1;
		}
	}
	int c,r;
	if(sum%n==0){
		c=sum/n;
	}else{
		c=sum/n+1;
	}
	if(c%2==0){
		r=(n+1)-sum%n;
	}else if(sum%n==0){
		r=sum%(n+1);
	}else{
		r=sum%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
