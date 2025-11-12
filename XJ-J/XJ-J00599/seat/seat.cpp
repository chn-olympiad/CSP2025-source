#include<bits/stdc++.h>
using namespace std;
int n,m,c[105],g,r,g1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	if(n==1&&m==1){
		cout<<"1 1";
	}
	r=c[1];
	g=m*n;
	sort(c+1,c+1+g);
	for(int i=m;i>=1;i--){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(c[g]==r){
					cout<<j<<" "<<i;
					return 0;
				}
				g--;
			} 
		}else{
			for(int j=1;j<=n;j++){
				if(c[g]==r){
					cout<<j<<" "<<i;
					return 0;
				}
				g--;
			} 
		}	
	}
	/*for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(c[i]<c[j]){
				swap(c[i],c[j]);
			}
		}
	}
	for(int i=1;i<=g;i++){
		if(c[i]==r){
			g1=i; 
		} 
	} 
	if(g1%n!=0){
		int i=m-g1%n;
		int j=g1/n+1;
		cout<<i<<" "<<j;
	}else{
		int i=m-g1%n;
		int j=g1/n;
		cout<<j<<" "<<i;
	}*/
	return 0;
} 
