#include<bits/stdc++.h>
using namespace std;
int r[10];
int o[10];
int l[10];
int main(){
	int n,m,k,u,v,w,x=0,y=0,c;
	r[1]=1;
	l[1]=1;
	cin>>n>>m>>k;
	for(int q=1;q<=n;q++){
		x=2*x+1;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		if(u+v==x/2){
		    y=y+w;
		    for(int i=1;i<=10;i++){
		    	if(r[i]!=u||r[i]!=v){
		    		r[i+1]=u;
		    		r[i+2]=v;
				}
			}
		}
	}
	for(int j=1;j<=k;j++){
		cin>>c;
		for(int p=1;p<=n;p++){
		    cin>>o[p];
		    for(int i=1;i<=10;i++){
		    	if(r[i]!=l[p]){
		    	    y=y+o[p];
				}
			}
			l[p+1]=l[p]+1;
		}
	}
	cout<<y;
	    
	
	return 0;
}
