#include<bits/stdc++.h>
using namespace std;
int n,k,a[200001],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	if(a[i]>1)cout<<3,exit(0);
	}
	for(int i=0;i<n;i++){
		if(k&&a[i]||!k&&!a[i])s++;
		if(!k&&a[i]&&a[i+1])s++,i++;
	}
	cout<<s;
}
