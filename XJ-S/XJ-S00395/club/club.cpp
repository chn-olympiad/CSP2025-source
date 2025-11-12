#include <bits/stdc++.h>
using namespace std;
int r[4];
int main(){
	int t,n,nz[20000],w,c=0;
	int myd1,myd2,myd3;
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>nz[i];
		for (int j=0;j<=nz[i];j++){
			cin>>myd1>>myd2>>myd3;
			if(myd1>myd2>myd3 || myd1>myd3>myd2){
				r[1]++;
				c+=myd1;
			}
			if(myd2>myd1>myd3 || myd2>myd3>myd1){
				r[2]++;
				c+=myd2;
			}
			if(myd3>myd2>myd1 || myd3>myd1>myd2){
				r[3]++;
				c+=myd3;
			}
		}if(r[1]<=nz[i]/2 && r[2]<=nz[i]/2 && r[3]<=nz[i]/2)
			cout<<c<<endl;
		else break;
			
	}
	return 0;
}
