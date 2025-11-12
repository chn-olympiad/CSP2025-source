#include <bits/stdc++.h>
using namespace std;
int x,n,m,e,r;
int a[101],b[101];
int o=1,p=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=x;i++){
		cin>>e;
		if(i==1) r=e;
		a[e]++;
	}
	int d=1;
	for(int i=100;i>=1;i--){
		if(a[e]!=0){
		b[d]=i;
		d++;	
		} 
	}
	int k=0;
	for(int i=1;i<=x;i++){
		if(b[i]==r) break;
		if(k==0){	
			if(p%m==0){
				k=1;
				o++;
			}
			else p++;
		}
		else{
		if(k==1){	
			if(p%m==1){
				k=0;
				o++;
			}
			else p--;	
		}
		}
	}
	cout<<o<<" "<<p;
	return 0;
}
