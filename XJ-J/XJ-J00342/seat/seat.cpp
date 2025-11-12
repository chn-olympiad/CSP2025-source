#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r,c[1001],ming=0,hang,lie;
	double h;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	r=c[1];
	sort(c+1,c+n*m+1);
	for(int i=1;i<=n*m;i++){
		
		if(r==c[i]){
			ming=m*n-i+1;
			
		}
		
	}
    
	if(ming%n!=0){
		
		lie=int(ming/n)+1;
		h=ming*1.0/n*1.0;
		
		if(h==0){
			h=1;
		}
		
		for(int i=100;i>=1;i--){
			
			if(h>i){
				h=i+1;
				break;
			}
		}
		
		if(int(h)%2!=0){
			hang=ming%n;
			
		}
		else if(int(h)%2==0){
			hang=n-ming%n+1;
			
		}
	}
	else if(ming%n==0){
		lie=ming/n;
		h=ming*1.0/n*1.0;
		if(h==0){
			h=1;
		}
		for(int i=100;i>=1;i--){
			if(h>i){
				h=i+1;
				break;
			}
		}
		
		if(int(h)%2!=0){
			hang=n;
		}
		else if(int(h)%2==0){
			hang=1;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
