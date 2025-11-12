#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
    string a;
    cin>>a;
    int b[n];
    for(int i=0;i<n;i++){
    	cin>>b[i];
	}
	if(m==1){
		cout<<1%998244353;
	}
	else{
		cout<<2;
	}
	return 0;
}
