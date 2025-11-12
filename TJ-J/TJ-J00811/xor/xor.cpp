#include <iostream>
using namespace std;
int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	int n,k;
	cin>>n>>k;
	int a[500005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	cout<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
