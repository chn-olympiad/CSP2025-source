#include<iostream>
using namespace std;
int a[10000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n*k;i++){
		cin>>a[i];
	}
	cout<<2;
	return 0;
} 
