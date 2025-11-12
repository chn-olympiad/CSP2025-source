#include <iostream>
using namespace std;
int a[11][11];
int main(){
	int b,c,n;
	cin>>b>>c;
	for(int i=0;i<=b;i++){
		for(int j=0;j<=c;j++){
			cin>>a[i][j];
			cout<<a[1][1]-a[i][j];
		}
	}
	return 0;
}
