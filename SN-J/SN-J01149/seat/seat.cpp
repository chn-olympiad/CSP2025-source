#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	int cj,s1;
	int h=1,l=1;
	cin >>cj;
	s1=cj;
	for(int i=2;i<=m*n;i++){
		cin >>cj;
		if(l%2!=0){
		   if(cj>s1 ){
			  if(h==n&&i==n*m){
				break;
			  }else if(h==n){
			    l++; 
			  }else{
			  	h++;
			  }
		   }
		}else{
			h=n;
			if(cj>s1){
				if(h==1&&i==n*m){
					break;
				}else if(h==1){
					l++;
				}else{
				    h--;	
				}
			}
		}
	}
	cout <<h<<l;
	return 0;
}
