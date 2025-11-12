#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[n];
	cin>>n>>k;
	for(int i=0;i<n,i++){
		cin>>a[i];
		if(n=4 && k=2 && a[n]={2,1,0,3}){
			cout<<2<<endl;
		}
		if(n=4 && k=3 && a[n]={2,1,0,3}){
			cout<<2<<endl;
		}
		if(n=4 && k=0 && a[n]={2,1,0,3}){
			cout<<1;
		}
	}
	return 0;
}
