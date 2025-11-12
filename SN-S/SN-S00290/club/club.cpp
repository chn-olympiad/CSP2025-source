#include<iostream>
using namespace std;
#include<fstream>


int main(){
	//std::ifstream cin("club.in");
	//std::ofstream cout("club.out");
	
	int boring=0;
	cin>>boring;
	
	
	for(int z=1;z<=boring;z++){
		int max[]={0};
		int n=0;
		int gu=0;
		int total=0;
	
		
		cin>>n;
		int a[n][3]={0};
		
		for(int i=1;i<=n;i++){
			
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}

	int man[3]={0};
	for(int u=1;u<=n;u++){
		
		for(int j=1;j<=3;j++){
			
			if(a[u][j]>max[u]){
				if(man[j]>=0.5*n){
					
				}
				
				else{
				max[u]=a[u][j];
				gu=j;
				}
			}
			
			
			if(j==3){
				man[gu]++;
			}
			cout<<z;
	}
	cout<<z;
	
	}
	
	
	
	for(int l=1;l<=n;l++){
		total=total+max[l];
}
}
	return 0;
}
