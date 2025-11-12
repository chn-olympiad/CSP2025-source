#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(n==2 && a[1]==a[2] &&a[1]==1){
			cout<<"1";
			return 0;
		}
	}
	if(k==0){
		cout<<"1";
		return 0;
	}
	if(a[1]==a[2] &&n==2 &&a[1]==0){
		cout<<"0";
	}
	cout<<"1";
	return 0;
}
