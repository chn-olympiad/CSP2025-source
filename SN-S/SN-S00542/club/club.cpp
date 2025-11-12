#include<iostream>
using namespace std;
int t=0,n=0,ma=0,m[3],w=0,x=0,y=0,g=0,h=0;
long long a[3][20005],c[20005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		n=0;
		w=0;
		ma=0;
		x=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			a[0][j]=0;
			a[1][j]=0;
			a[2][j]=0;
			
		}
	
		for(int j=1;j<=n;j++){
			cin>>a[0][j]>>a[1][j]>>a[2][j];
			}
		for(int j=1;j<=n;j++){
				c[j]=0;
			}
		m[0]=0;
		m[1]=0;
		m[2]=0;
		for(int q=1;q<=n;q++){
			ma=-1;
			h=0;
			g=0;
			for(int z=0;z<=2;z++){
				for(int j=1;j<=n;j++){
					
						if(m[z]<(n/2)&&c[j]==0){
							if(a[z][j]==ma){
								if(a[(z+1)%3][j]>a[(z+2)%3][j]){
									g=a[(z+1)%3][j];
								}
								else{
									g=a[(z+2)%3][j];
								}
								if(g<=h){
									h=g;
									x=z;
									y=j;
								}
							}
						if(a[z][j]>ma){
							ma=a[z][j];
							x=z;
							y=j;
							if(a[(z+1)%3][j]>a[(z+2)%3][j]){
									g=a[(z+1)%3][j];
								}
								else{
									g=a[(z+2)%3][j];
								}
						}
							
						if(z==0&&j==1){
						ma=a[z][j];
						x=0;
						y=1;
						if(a[(z+1)%3][j]>=a[(z+2)%3][j]){
						g=a[(z+1)%3][j];
							}
						else{
							g=a[(z+2)%3][j];
						}
						}
					}
				}
			}
			w+=ma;
			m[x]++;
			c[y]=1;
		}
		
			cout<<w<<'\n';
	}
	
	return 0;
}
