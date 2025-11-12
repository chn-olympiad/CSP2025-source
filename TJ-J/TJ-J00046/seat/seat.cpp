#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],l,c,p=1,o,q;
int main(){
   freopen("seat.in","r",stdin); 
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++){
   	cin>>a[i];
   }
   int t=a[1];
   for(int i=1;i<=n*m;i++){
   		for(int j=1;j<=m*n;j++){
		   if(a[j]<a[j+1]){
   			int u=a[j];
   			a[j]=a[j+1];
   			a[j+1]=u;
   		}
	   }
   }
   for(int i=1;i<=n*m;i++){
   	if(a[i]==t){
   	  for(int d=1;d<=m;d++){
   	  	if(i%n==0&&i/n==d){
   	  		c=d;
   	  		o=c;
   	  		q++;
			}
		if(i/n==d-1){
			c=d;
			continue;
		}
	}
	    if(q!=0){
	    	c=o;
		}
	  	if(c%2==1){
	  		for(int j=1;j<=n;j++){
	  		if(i%n==j){
	  			l=j;
	  			continue;
			  }
			if(i%n==0){
				l=n;
				continue;
			}
		}
		}
		else{
			for(int j=n-1;j>0;j--){
			p++;
			if(i%n==j){
			  	l=p;
			  	continue;
			}
			if(i%n==0){
				l=1;
				continue;
			}
		}
		}
	}
   }
   cout<<c<<" "<<l;
   return 0;
}
