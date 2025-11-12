#include<bits/stdc++.h>
using namespace std;
int a[100000],n,k;
bool b[100000];
bool f(int s,int w){
	int h=a[s];
	if(b[s]==1){
		return 0;
	}
	for(int i=s+1;i<=w;i++){
		if(b[i]==1){
			return 0;
		}
		h=(h^a[i]);
	}
	if(h==k){
		for(int i=s;i<=w;i++){
			b[i]=1;
		}
		return 1; 
	}
	else{
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int z=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=0;i--){
		for(int j=0;j<=n-i;j++){
			if(f(j,j+i-1)){
				z++;
			}
		}
	}
	cout<<z;
}
