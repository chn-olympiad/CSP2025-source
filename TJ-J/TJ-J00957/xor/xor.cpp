#include<bits/stdc++.h>
using namespace std;
int yhh(int a[],int x){
	for(int i=0;i<x-1;i++){
		a[i+1]=(a[i]^a[i+1]);
	}
	return a[x-1];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int num=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(a[j]==k&&yhh(a-j-1,n)==k){
				if(i+j>num) num=i;
			}
		}	
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
