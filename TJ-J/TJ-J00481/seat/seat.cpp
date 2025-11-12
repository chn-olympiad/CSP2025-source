#include<iostream>
using namespace std;
int n,m;
int sy;
int sx,f=1;
int ansx,ansy;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>sx;
	for(int i=2;i<=n*m;i++){
		cin>>sy;
		if(sy>sx){
			f++;
		}
	}
	cout<<f<<endl;
	if(f==1){
		cout<<1<<" "<<1;
		return 0;
	}
	if(f%n==0){
		ansy=f/n;
	}else{
		ansy=f/n+1;
	}
	if(n%2!=0){
		if(f%2!=0){
			if(f%n==0){
				ansx=n;
			}else{
				ansx=f%n;
			}
		}else{
			if(f%n==0){
				ansx=1;
			}else{
				ansx=n-f%n+1;
			}
		}
	}else{
		if(f%2==0){
			if(f%n==0){
				ansx=n;
			}else{
				ansx=f%n;
			}
		}else{
			if(f%n==0){
				ansx=1;
			}else{
				ansx=n-f%n+2;
			}
		}
	}
	
	cout<<ansy<<" "<<ansx;
	return 0;
}
