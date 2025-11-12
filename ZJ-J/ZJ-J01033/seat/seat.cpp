#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a,b,flag;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	x=n*m-1;
	while(x--){
		cin>>b;
		if(b>a){
			flag++;
		}
	}
	int z=flag/n;
	cout<<z+1<<' ';
	if(z%2==0){
		cout<<flag%n+1;
	}else{
		cout<<n-flag%n;
	}
	return 0;
}