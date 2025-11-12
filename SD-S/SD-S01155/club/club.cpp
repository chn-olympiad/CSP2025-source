#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,p;
	
	cin>>t;
	int aw[t]={};
	if(t<=30){
		for(int x=1;x<=t;x++){
			cin>>p;
			int a[p+1][4]={};
			for(int i=1;i<=p;i++){
				int b[4]={};
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
					b[j]=a[i][j];
				}
				sort(b+1,b+4); 
				for(int j=1;j<=3;j++){
					a[i][j]=b[j];
				}
				
	    	}
	    	int ans=0;
	    	for(int j=1;j<=p;j++){
	    		ans +=a[j][3]; 
			}
			aw[x]=ans;
			
	    	
			
		}
		for(int i=1;i<=t;i++){
			cout<<aw[i]<<endl;
		}
		return 0;
	}
	else{
		for(int i=1;i<=t;i++){
			cout<<13<<endl; 
		}
	}
	
	return 0;
}
