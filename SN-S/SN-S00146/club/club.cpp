#include <bits/stdc++.h>//姜润轩 SN-S00146 陕西省丹凤中学
using namespace std;
int a[100000][100000];
int h[100000];
int main(){
	freopen ("club.in","r","stdin");
	freopen ("club.out","w","stdout");
	int a,n,t,x,p,q,y,d,i,j,x;
	cin>>n>>a[i][j];
	while (int d;1<=d<=10000;d++){
		while (int i;1<=i<=n;i++){
				if(a[i][1]>=a[i][2]){
		          if(a[i][2]>=a[i][3]){
		            d=a[i][1];
		            else
	              	    if(a[i][1]<=a[i][2]){
			              if(a[i][2]<=a[i]a[3]){
			                d=a[i][3];
			              else
			                d=a[i][2];
		                  }
	                    }
	 	          }
	            }
	    }
	}
	while(int x;1<=x<=t;x++){
		while(int i;1<=i<=n;i++){
			h[x]=d;
		}
	}
	if(d=a[i][1]){
		p++;
		else
		 if(d=a[i][2]){
			q++;
			else
			y++;
		 }
	}
	if(p>n/2){
		d=a[i][2];
		q++;
	 else
	    if(q>n/2){
	   	  d=a[i][1];
	   	  p++;
	   	 else
	   	    d=a[i][3];
	   	    y++;
	   }   
	}
	cout<<h[x];
	return 0;
}