#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][5];
int q,w,e;
int z[100005];
int x;
int s;
int sum,sm;
int vis[10005][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	for(int j=1;j<=t;j++){
		for(int i=1;i<=n;i++){
		    cin>>a[i][1]>>a[i][2]>>a[i][3];
	    	if(a[i][1]>=a[i][2]){
	    		if(a[i][1]>=a[i][3]){
	    			q++;
	    			vis[q][1]=a[i][1];
	    			if(q>n/2){
	    				sm=vis[q][1];
	    				for(int k=1;k<q;k++){
	    					if(vis[k][1]<sm){
	    						sm=vis[k][1];
	    						s++;
	    						z[s]=k;
							}
						}
						vis[z[s]][1]=x;
						vis[z[s]][1]=vis[q][1];
						q--;
					}
	    			sum+=a[i][1];
				}
				
				else {
				    e++;
				    vis[e][3]=a[i][3];
	    			if(e>n/2){
	    				sm=vis[e][3];
	    				for(int k=1;k<e;k++){
	    					if(vis[k][3]<sm){
	    						sm=vis[k][3];
	    						s++;
	    						z[s]=k;
							}
						}
						vis[z[s]][3]=x;
						vis[z[s]][3]=vis[e][3];
						e--;
					}
					sum+=a[i][3];
					
				}
			}
	    	else if(a[i][2]>=a[i][3]){
	    		w++;
	    		vis[w][2]=a[i][2];
	    			if(w>n/2){
	    				sm=vis[w][2];
	    				for(int k=1;k<w;k++){
	    					if(vis[k][2]<sm){
	    						sm=vis[k][2];
	    						s++;
	    						z[s]=k;
							}
						}
						vis[z[s]][2]=x;
						vis[z[s]][2]=vis[w][2];
						w--;
					}
				sum+=a[i][2];
	    		
			}
	    	else {
			    e++;
	    	    vis[e][3]=a[i][3];
	    			if(e>n/2){
	    				sm=vis[e][3];
	    				for(int k=1;k<e;k++){
	    					if(vis[k][3]<sm){
	    						sm=vis[k][3];
	    						s++;
	    						z[s]=k;
							}
						}
						vis[z[s]][3]=x;
						vis[z[s]][3]=vis[e][3];
						e--;
					}
	    		sum+=a[i][3];
	    		
			}
    	}
		cout<<sum<<"\n";
	}
	
	
	return 0;
}
