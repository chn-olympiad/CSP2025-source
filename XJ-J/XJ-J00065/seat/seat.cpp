#include<bits/stdc++.h>


using namespace std;
int num[110][110];
int nn[110];
int n,m; 
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	    cin>>nn[i];
	}
	int win=nn[1];
	sort(nn+1,nn+n*m+1,cmp);
	int d=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
	        for(int j=1;j<=m;j++){
				num[j][i]=nn[d];
			    d++;
			}			
		}
	    else{
	    	for(int j=m;j>=1;j--){
	    		num[j][i]=nn[d];
	    		d++;
			}
		}
	}
   	for(int i=1;i<=n;i++){
   	    for(int j=1;j<=m;j++){
            if(num[i][j]==win){
            	cout<<j<<" "<<i;
			}
		}	
	}
	return 0;
	
} 
