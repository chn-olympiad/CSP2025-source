#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int g=0;
		int h;
		cin>>h;
		int a[3][h];
		//JÐÐPÁÐ 
		for(int j=0;j<h;j++){//SHURU
			for(int p=0;p<3;p++){
			cin>>a[j][p];
		}
		}
		if(h==2){
			for(int e=0;e<3;e++){
				for(int r=0;r<3;r++){
					if(a[0][r]+a[1][e]>g&&r!=e){
						g=a[0][r]+a[1][e];
					}
			}
			}
			cout<<g;
		}
		else if(h==4){
			for(int e=0;e<3;e++){
				for(int r=0;r<3;r++){
					for(int x=0;x<3;x++){
						for(int y=0;y<3;y++){
							if(a[0][y]+a[1][x]+a[2][r]+a[3][e]>g){
								if((e!=y&&e!=r)||(e!=y&&e!=x)||(e!=y&&x!=y)||(y!=r&&y!=x)||(y!=r&&r!=x)||(r!=e&&x!=r)){
								
								cout<<g<<" ";
								g=a[0][y]+a[1][x]+a[2][r]+a[3][e];
								}
					}
			}
			}
		
			}
			}
			cout<<g;
		}
		else{
		for(int j=0;j<3;j++){//±éÀú
			for(int p=0;p<h;p++){
			 if(a[j][p]+a[p][j]+a[j][j]+a[p][p]>g&&a[p][p]!=a[j][j]){
			 	g=a[j][p]+a[p][j]*h;
			 } 
		}
		}
		cout<<g;
	
		
	}	
	}	 

	return 0;
}
