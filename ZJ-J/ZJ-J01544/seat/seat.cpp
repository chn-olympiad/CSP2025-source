#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,r;
	cin>>n>>m;
	int c[n*m];
	int p[n][m];
	for(int i=0;i<n*m;i++){
		cin>>c[i];
	}
	r=c[0];
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(c[i]<c[j]){
				int a=c[i];
				c[i]=c[j];
				c[j]=a;
			}
		}
	}
	int b=0;
	int z=0;
	int j=0;
	for(int i=0;i<m;i++){
		for(;j<n;){
			if(j>=0){
				p[i][j]=c[b];
				b++;
				if(r==p[i][j]){
					cout<<i+1<<" "<<j+1<<endl;
					return 0;
				}
				if(z==0){
					j++;
				}else{
					j--;
				}	
			}else if(j<0){
				j++;
				break;
			}			
		}
		if(j==n){
			j--;
		}
		if(z==0){
			z=1;
		}else{
			z=0;
		}
	}
	return 0;
}