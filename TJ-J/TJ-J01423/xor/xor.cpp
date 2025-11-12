#include<bits/stdc++.h>
using namespace std;
int n,f;
int a[500005];

int panduan(int l,int r){
	int aaa = 0;
	for(int i=l+1;i<=r;i++){
		aaa=aaa^a[i];
	}
	return aaa;
}
int suuum(int l,int r){
	if(l>=r){
		return 0;
	}
	int sum = 0;
	bool flaag = 0;
	for(int i=1;i<r-l;i++){
		for(int j=l;j+i<=r;j++){
			if(panduan(j,j+i)==f){
				flaag = 1;
				sum = max(sum,suuum(j+i,r));
			}
		}
	}
	if(flaag = 1){
		return 1+sum;
	}else{
		return 0;
	}
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<""<<suuum(0,n);
	
	return 0;
}
