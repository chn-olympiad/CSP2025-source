#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005],x=0,b[5005],m=0,y=3;
    cin>>n;
    for(int j=1;j<=n;j++){
    
	    cin>>a[j];
	    for(int i=1;i<=y;i++){
	        b[j]=0;
	        
			if(a[i]>b[j]) b[j]=a[i];
			m=a[i]+m;
			if(m>2*x) x++;
			
	    }
		m=0;
		y++;
    }
    
    cout<<x;
	return 0;	
} 
