#include<iostream>
using namespace std;
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out ","w",stdout);
	int n,m,j,h,c=1,v=1,b=0;
	cin>>n>>m;
	int p[m*n];
	for(int a=0;a<m*n;a++){
		cin>>p[a];
	}
		h=p[0];
	for(int a=0;a<m*n;a++){
			for(int k=a;k<m*n;k++){
			if(p[a]<p[k]){
			swap(p[a],p[k]);
		}
	}
	}
		for(int a=0;a<m*n;a++){
			if(p[a]==h){
				j=a;
				break;		}
		}
	
		
		
				
		for(int a=1;a<=m;a++){
			if(j==b){
				cout<<c<<" "<<v;
				return 0;
			}
			if(a%2==0){
				for(int l=2;l<=n;l++){
				v--;
				b++;
					if(j==b){
				cout<<c<<"  "<<v;
				return 0;
			}
				}
				
			}
			else{
					if(a%2==1){
				for(int l=2;l<=n;l++){
					v++;
					b++;
					if(j==b){
				cout<<c<<"  "<<v;
				return 0;
							}
				}
				
			}
			}
			c++;
			b++;
		}
		fclose(stdin);
		fclose(stdout);
	return 0;	
}
