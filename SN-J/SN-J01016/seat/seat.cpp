#include<bits/stdc++.h>     
using namespace std; 
int n,m;
int b[120];       																																																																																																																																																																																																																																																																																																																																																																																																																																																														
int z[120];
int o=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];	
	}
	int q=b[1];
	int a=n*m;
	sort(b+1,b+a+1);
	for(int i=a;i>=1;i--){
		z[o]=b[i];
		o++;
	}
	int o=1;
	for(int i=1;i<=m;i++){
		
		for(int j=1;j<=n;j++){
			if(z[o]==q){
				cout<<i<<" "<<j;
				return 0;
			}else{
				o++;
			}
		}
		i++;
		
		for(int k=n;k>=1;k--){
			if(z[o]==q){
				cout<<i<<" "<<k;
				return 0;
			}else{
				o++;
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


