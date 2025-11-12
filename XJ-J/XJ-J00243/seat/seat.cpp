#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xr;
	cin>>n>>m>>xr;
	a[xr]++;
	for(int i=1;i<=n*m-1;i++){
		cin>>a[i];
		a[i]++;
	}
	int x=1,y=1,cz=100;
	bool sx=1,pd=1;
	for(int i=1;i<=100;i++){
		if(a[i]!=0){
			if(cz==xr){
				cout<<y<<" "<<x;
				return 0;
			}
			//cout<<y<<" "<<x<<endl;
			if((x==n||x==1)&&pd==0){
				if(x==n){
					sx=0;
					
				}else{
					
					sx=1;
				}
				pd=1;
				y++;
			}else{
				if(pd=1){
					if(sx==1){
						x++;
					}else {
						x--;
					}	
					pd=0;
				}
				
			}
			
			//cout<<y<<" "<<x<<endl;
				
			
		}
		cz--;
		
	}

	
	return 0;
} 
