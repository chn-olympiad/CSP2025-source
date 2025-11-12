#include <bits/stdc++.h>
using namespace std;
int a[1001];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int t=0;
	int p=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			int j=i/n;
			
			if(n==1 && m==1){
				t=1;
				p=1;
				break;
			}
			else if(i<=n){
				p=i;
				t=1;
				break;
			}
				 else if(n==1){
				 	p=1;
				 	t=i;
				 	break;
				 }	  else {
				 		if( j%2==0 ){
				 			if(i%2==0){
				 				t=1;
				 				p=j;
						 		} 
							else {
								t=i-j*n;
								p=j+1;
						}
					 }  else {
					 		t=n*2-i+1;
					 		p=j+1;
				 }
		}
}}
	cout<<p<<" "<<t;
	return 0;
}
