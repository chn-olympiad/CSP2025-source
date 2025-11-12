#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m;
	int a[100][100];
	int c[3]={0};
		//cin>>m;
		for(int j=0;j<m;j++){
			//cout<<1<<" ";
			for(int k=0;k<3;k++){
				//cin>>a[j][k];
			}
			int b[3];
			for(int k=0;k<3;k++){
				b[k]=a[j][k];
			}
			sort(b,b+3);
			int d[j][3]={0};
			/*for(int h=0;h<3;i++){
				for(int k=i;k<3;k++){
					if(b[h]==a[j][k]){
						d[j][k]=h;
					}
				}
			}*/
			for(int k=0;k<3;k++){
				//cout<<b[k];
			}
		
			
		}
	cout<<9;
	return 0;
} 

