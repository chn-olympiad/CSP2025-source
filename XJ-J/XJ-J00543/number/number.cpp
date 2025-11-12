#include<nits/stdc++.h>
using namespace std;
int main(){
	int n,m,s;
	int a[1001];
	int b[1001]
	cin>>number.in;
	for(int i=0;i<=3;i++){
		cin>>a[i];
		if(a[i]>=01 && a[i]<=9){
			b[i]=a[i];
		}
		if(b[i]<a[i+1]){
			swap(b[i],b[i+1]);
		}
	}
	for(int i=0;i<=3;i++){
		cout<<b[i];
	}
} 
