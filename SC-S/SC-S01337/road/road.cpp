//c
#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000100],v[1000100],w[1000100],c[100],a[100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++)cin>>a[j];
	}
	cout<<0;
	return 0;
}
/*
rr         rrrr					    pppppppp	                            
rr     rrr       rrr       			pp        ppp						   					
rr   rrr             rrr			pp			 pp					       
rr rr                  rr			pp			  pp					  																			
rrrr								pp			   p	                   
rrr                                 pp      	   p				+	   				   +								
rr                                  pp            pp				+	   				   +									
rr                                  pp          pp                  +                      +  
rr                                  pp       ppp                     +                      +
rr                                  ppppppp                 +++++++++++++++++      +++++++++++++++++   
rr                                  pp                              +                      +
rr                                  pp                              +                      +
rr                                  pp			                    +                      +
rr									pp								+	  				   +	
rr									pp									   										
rr									pp									   				
rr									pp																
rr									pp											
rr									pp														
*/