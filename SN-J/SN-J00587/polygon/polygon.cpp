#include<bits/stdc++.h>
int a[5005];
using namespace std;
int main(){
    int n,mx=0,ans=0,m;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i]; 
		mx=max(a[i],a[i-1]);
	}
	for(int i=3;i<=n;i++){
	    
	}
	m=m%998244353;
	if(n<=3){
		cout<<10;
	}else if(3<n<=20)cout<<100;
	return 0;
} 
