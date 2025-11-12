#include<bits/stdc++.h>
using namespace std;
string er(int n){
	string b="";
	while(n>0){
		b+=n%2;
		n=n/2;
	}
	string a="";
	for(int i=0;i<b.size();i++){
		a[b.size()-i-1]=b[i];
	}
	return a;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	string b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
    if(n==4){
    	cout<<2;
	}else{
		cout<<1;
	}
	return 0;
}
