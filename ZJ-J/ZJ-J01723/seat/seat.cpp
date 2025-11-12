#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
int sum=1, x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	for(int i=1;i<=n*m;i++){
		if(a[i]>x)
			sum++;
	}
	int y;
	if(sum%n==0){
		y=sum/n;
	}
	else {
		y=sum/n+1;
	}
	cout<<y<<" ";
	if(y%2==0){
		if(sum%n==0)
			cout<<1;
		else{
			cout<<n+1-sum%n;
		}
	}
	else{
		if(sum%n==0){
			cout<<n;
		}
		else{
			cout<<sum%n;
		}
	}
	return 0;
}
