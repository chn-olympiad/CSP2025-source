#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,r;
	cin>>n; 
	int a[n],d[n]={0};
	int z1[1000],z2[1000],z3[1000];
	for(int i=0;i<n;i++){
		cin>>a[i];
		r=a[i]/2;
		int r1=0,r2=0,r3=0;
		for(int j=0;j<a[i];j++){
			cin>>z1[i]>>z2[i]>>z3[i];
			if(z1[i]>z2[i]&&z1[i]>z3[i]&&r1<=r){
				r1=r1+1;
				d[i]=d[i]+z1[i];
			}
			if(z2[i]>z1[i]&&z2[i]>z3[i]&&r2<=r){
				r2=r2+1;
				d[i]=d[i]+z2[i];
			}
			if(z3[i]>z1[i]&&z3[i]>z2[i]&&r3<=r){
				r3=r3+1;
				d[i]=d[i]+z3[i];
			}
		}
	} 
	for(int i=0;i<n;i++){
		cout<<d[i]<<endl;
	}
	return 0;
} 
