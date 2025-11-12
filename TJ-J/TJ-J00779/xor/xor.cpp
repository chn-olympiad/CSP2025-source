#include<bits/stdc++.h>
using namespace std;
int yh(int p,int q){
	if(p-q<0){
		return q-p;
	}
	else{
		return p-q;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int l[n];
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	int l1[n];
	int g;
	if(n==2&&yh(l[0],l[1])==0){
		cout<<2;
	}
	else if(n==1&&yh(l[0],l[1])==0){
		cout<<1;
	}
	else if(n==1&&yh(l[0],l[1])==0){
		cout<<1;
	}
	for(int i=0;i<n;i++){
		g=l[i];
		for(int j=0;g>0;j++){
			l1[i]+=g%2*pow(10,j);
			g/=2;
		}
	}
	
	return 0;
} 
