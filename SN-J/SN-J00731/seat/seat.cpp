#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+m*n,greater<int>());
	int f;
	for(int i=0;i<n*m;i++){
		if(r==a[i]){
			f=i+1;
			break;
		}
	}
	if(f%n==0){
		if(f/n%2==0){
			cout<<f/n<<' '<<1;
		}else{
			cout<<f/n<<' '<<n;
		}
	}else{
		if(f/n%2!=0){
			cout<<f/n+1<<' '<<m-(f-n*(f/n))+1;
		}else{
			cout<<f/n+1<<' '<<f-n*(f/n);
		}
	}
	return 0;
}
