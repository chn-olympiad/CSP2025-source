#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in",r,"seat.out");
	freopen("seat.in",w,"seat.out");
	int n,m;
	cin>>n>>m;
	int a[100+5];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
sort(a+1,a+(n*m+1));
int num;
int t=1;
for(int i=n*m;i>=1;i--){
	if(a[i]==s){
		num=t;
		break;
	}
	t++;
}
if(num<=n){
	cout<<"1"<<" "<<num;
	return 0;
}
if((num/n+num%n+1)%2==0){
	cout<<num%n+num/n<<" "<<num%n;
	return 0;
	}else{
	cout<<num%n+num/n<<" "<<num/n+1;
	return 0;
	}
	return 0;
}