#include<bits/stdc++.h>
using namespace std;
int main(){	 
	  int x,y,n,p;
    cin>>x>>y>>n>>p;
    int a,b;
    a=p/10*n;
    if(p<x&&a>n){
        b=p;
    }else{
        b=p-y;
    }
    cout<<b;
    return 0;
}
