#include<bits/stdc++.h>
using namespace std;
std::ifstream cin(seat.in);
std::ofstream cout(seat.out);
int main(){
	int n,m;
	cin>>n>>m;
	long long a[n*m];
	for(int i=0;i<n*m;++i){
		cin>>a[i];
	}
	int b=a[0],c,x,r;
	sort(a,a+n*m,false);
	for(int i=0;i<n*m;++i){
		if(a[i]==b) c=i+1;
	}
	if(c%n!=0){
		x=c/n+1;
	}
	else{
		x=c/n;
	}
	if(x%2==1){
		r=c%n;
	}
	else{
		r=n-c%n;
	}
	cout<<x<<' '<<r;
	return 0;
}

