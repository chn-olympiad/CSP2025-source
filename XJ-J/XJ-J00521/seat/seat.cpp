#include <iostream>
using namespace std;
int a[11][11];
int main(){
	int b,c,d,n;
	cin>>b>>c;
	for(int i=0;i<=b;i++){
		for(int j=0;j<=c;j++){
			cin>>n;
			
			if(a[j][i]<a[j][i-1]){
				a[j][i]=b;
				a[j][i]=a[j][i-1];
				a[j][i-1]=b;
			}
			
		}
	}
	d=a[1][1];
	for(int i=0;i<=b;i++){
		for(int j=0;j<=c;j++){
			if(a[i][j]==d){
				cout<<i<<' '<<j<<endl;
			}
		}
	}
	return 0;
}
