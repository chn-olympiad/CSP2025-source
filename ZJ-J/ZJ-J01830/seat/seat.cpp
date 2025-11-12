#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,s,x3=1,y3=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		r=a[1];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			s=n*m-i+1;	
		}
	}
	y3=((s-1)/n)+1;
	if(y3%2==1){
		x3=(s-1)%n+1;
	}
	else{
		x3=n-(s%n)+1;
	}
	cout<<y3<<" "<<x3;
	return 0;
}
