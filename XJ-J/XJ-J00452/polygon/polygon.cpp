#include<bits/stdc++.h>
using namespace std;
int main(){	 
	   int x,y,p,n,m;
    cin>>x>>y>>n>>p;
    int a,b;
    a=p/10*n;
    if(p<x){
        b=p;
    }
	else{
        b=p-y;
        p=b^(y);
		cout<<b;
		
    	for(int i=0; 1<i<n*m; i++) {
		i=x-i;
		cout<<i;
	}
}
    return 0;
}
