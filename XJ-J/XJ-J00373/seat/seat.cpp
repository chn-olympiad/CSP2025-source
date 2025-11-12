#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,arr[110];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	int r=arr[0],count;
	sort(arr,arr+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(r==arr[i]){
			count=i+1;
		} 
	}
	if(count<=n){
		cout<<'1'<<' ';
	}else{
		if(count%n==0){
			cout<<count/n<<' ';
		}else{
			cout<<count/n+1<<' ';
		}
	}
	if((count/n)%2!=0){
		if(count%n==1||count%n==0){
			cout<<n;
		}else
		cout<<n-(count%n)+1;
	}else{
		if(count%n==0){
			cout<<1;
		}else{
			cout<<count%n;
		}
	}
	return 0;
}
