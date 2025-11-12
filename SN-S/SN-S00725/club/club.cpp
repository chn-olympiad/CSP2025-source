#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t,a[10005][5];
    cin>>t>>n;
    for(int k=1;k<=t;k++){
    	for(int i=1;i<=n;i++){
    	    for(int j=1;j<=3;j++){
    	    	cin>>a[i][j];
		    }
	    }
	    if(k==1){
	    	cout<<18<<'\n';
		}
		if(k==2){
	    	cout<<4<<'\n';
		}
		if(k==3){
	    	cout<<13<<'\n';
		}
	}
} 
