#include<iostream>
using namespace std;
int c=1,x,y,a[11][11],b=1;
int main(){
	int m,n;
	cin>>n>>m;
	cin>>x;
	for(int i=2;i<=m*n;i++){
		cin>>y;
		if(y>x){
			c++;
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				if(b==c){
					cout<<i<<' '<<j;
					return 0;
				}
				b++;
			}
		}
		else{
			for(int j=1;j<=m;j++){
				if(b==c){
					cout<<i<<' '<<j;
					return 0;
				}
				b++;
			}
		}
	}
	return 0;
} 
