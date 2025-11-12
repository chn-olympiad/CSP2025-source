#include<bits/stdc++.h>
using namespace std;
int n,arr[5001],jg,cc;
int aa(int nn){
	for(int i=1;i<=nn;i++){
		cc+=i;
		if(cc>=arr[nn-1]*2){
		    jg++;
	}
		if(nn==1){
			return cc;
		}	
		}	
	cc=0;
	aa(nn-1);		
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	
	    aa(n);	
		

	cout<<2*jg+1;
    return 0;
}
