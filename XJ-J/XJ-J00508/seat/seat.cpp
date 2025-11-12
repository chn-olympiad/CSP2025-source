#include<iostream>
using namespace std;
int main (){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int s=0;s<=n*m-1;s++){
		cin>>a[s];
	} 
	return 0;
}
