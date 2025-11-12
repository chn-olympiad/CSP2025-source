#include<bits/stdc++.h>
using namespace std;
long long n,k;
int v[101];
int main(){
	int a[101];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(k==a[i]){
			v[i]==1;
		}
	}
	if(v[0]==1||v[n]==1){
		cout<<"2";
	}else{
		cout<<"1";
	}
}

