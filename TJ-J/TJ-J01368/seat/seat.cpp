#include <bits/stdc++.h>
using namespace std;
int n,m,p=1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+5];
	cin>>a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]) p++;
	}
	if(p%m==0) x=p/m;
	else x=p/m+1;
	if(x%2==1){
		if(p%n==0) y=n;
		else y=p%n;
		cout<<x<<' '<<y;
		return 0;
	}
	else{
		if(p%n==0) y=1; 
		else y=n-p%n+1;
		cout<<x<<' '<<y;
		return 0;
	}
}
