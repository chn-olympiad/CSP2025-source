#include <iostream>
using namespace std;
int a[500];
int main(){
	int a,n,b=0;
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(a[j]+=a[j+1]>2*a[j+1]){
				b++;
			}
		}
	}
	cout<<b;
	return 0;
}
