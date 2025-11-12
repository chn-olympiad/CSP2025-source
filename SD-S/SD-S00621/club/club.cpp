#include<bits/stdc++.h>
using namespace std;
bool suc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int n,t,r=0;
    int r1;
    cin>>t;
    int a1,a2,a3;
    for(int i=1;i<=t;i++){
    	cin>>n;
		if(n>(n/2)&&n%2!=0){
    	    suc=false;
	    }
        for(int j=1;j<=n;j++){
    		cin>>a1>>a2>>a3;
		    r1=max({a1,a2,a3});
			r=r1+r;
	    }
	}
	cout<<r<<endl;
	return 0;
}  
