#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int l;
int y;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	y=n*m;
	for(int i=1;i<=y;i++){
		cin>>a[i];
	}
	int x;
	x=a[1];
	sort(a+1,a+1+y);
	for(int j=1;j<=y;j++){
		if(a[j]==x){
			l=y-j+1;
			break;
		}
	}
	if(l<n){
		c=1;
	}
	else{
		if(l%n==0){
			c=l/n;
		}
		else{
			c=l/n;
			c++;
		}
	}
	if(l%n==0){
		if(c%2==0){
			r=1;
		}
		else{
			r=n;
		}
	}
	else{
		if(c%2==0){
			r=n-(l%n)+1;
		}
		else{
			r=l%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
