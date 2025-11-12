#include <bits/stdc++.h>
using namespace std;
int arr[10000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n>>m;
	int x;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
		if(i==1){
			x=arr[i];
		}
	}
	sort(arr+1,arr+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(arr[i]==x){
			x=i;
			break;
		}
	}
	int a;
	int b;
	if(x%n==0){
		a=x/n;
		b=x%n+n;
	}else{
		a=x/n+1;
		b=x%n;
	}
	cout<<a<<" ";
	if(a%2==0){
		cout<<n+1-b;
	}else{
		cout<<b;
	}
	return 0;
}
