#include <iostream>
using namespace std;
int main (){
	int n;
	int m;
	cin>>n>>m;
	int sum=0;
	sum=n*m;
	int a[sum];
	for(int i=0;i<sum;i++){
		for(int j=0;j<sum;j++){
			if(a[1]<a[j+1]){
				n++;
				m++;
			}
		}
	}
	cout<<n<<m;
	return 0;
}
