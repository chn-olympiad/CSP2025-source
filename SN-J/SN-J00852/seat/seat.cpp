#include<bits/stdc++.h>
using namespace std;
int main( ){
	freopen("seat.in.txt","r",stdin);
//	freopen("seat.out.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[m*n],len=0,cup,r,i1=0;
	int seat[n][m];
	for(int i=0;i<n*m;i++)
	    cin>>a[i]; 
	r=a[0];
	for(int i=0;i<n*m;i++)
	cout<<a[i]<<"   ";
	cout<<endl<<n<<"  "<<m<<endl<<n*m<<endl;	
 	for(int i=0;i<n*m;i++)
 		cout<<i;
		for(int j=0;j<n*m;j++){
		
			i1++;}
			if(a[j]<a[j]){
				cup=a[i];
				
				a[i]=a[j];
				a[j]=cup;
			}
		
			cout<<1<<endl;
			cout<<a[i];
		}
	}
	
	
  for(int i=1;i<=n;){
   	    for(int j=1;j<=m;j++){
   	        seat[i][j]=a[i1];
   	        if(a[i1]==r){
   	        	cout<<i<<"  "<<j;
   	        	i+=100;
   	        	j+=100;
			   }
   	        i1++;}
   	    i++;
   	    for(int j=m;j>=1;j--){
   	    	seat[i][j]=a[i1];
   	    	if(a[i1]==r){
   	        	cout<<i<<"  "<<j;
   	        	i+=100;
   	        	j+=100;
   	            }
   	    	i1++;
		   }
		i++;
   }
	
return 0;
}
