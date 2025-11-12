#include<bits/stdc++.h>
using namespace std;
int c,n,answer,a[1000100][5];
void dfs (int i,int mem1,int mem2,int mem3,int ans){
	    if(ans>answer){
		
	}
	    int x=n/2;
        if(x>a[i][1]){
    	    dfs(i+1,mem1+1,mem2,mem3,ans+a[i][1]);
	}
        if(x>a[i][2]){
    	    dfs(i+1,mem1+1,mem2,mem3,ans+a[i][2]);
    }
        if(x>a[i][3]){
   	        dfs(i+1,mem1+1,mem2,mem3,ans+a[i][3]);
    }
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	while(){
		for(int i=0;i<=n;i++){
			    cin>>a[i][1]>>a[i][2]>>a[i][3];
		    }
		}
		cout<<a[i][1]<<endl<<a[i][2]<<endl<<a[i][3]<<endl;
	return 0;
}
