#include<bits/stdc++.h>
using namespace std;
long long n,x,k;
int a[101],v[101];
bool d(int b){
	for(int i=3;i<=n;i++){
		int e[i];
		for(int j=0;j<i;j++){
			b+=a[j];
			if(b/2>a[i-1]){
			return 1;
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<d(0);
	return 0;
	
} 
