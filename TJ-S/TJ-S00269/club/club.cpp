#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int n;
	int t;
	

	int tnum[t];
	int zhz;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> zhz;
		int maxtemp=0,ans=-1;
		int zhza[zhz+1]={};
		int zhzb[zhz+1]={};
		int zhzc[zhz+1]={};
		for(int j=0;j<zhz;j++){
			cin >> zhza[j] >> zhzb[j] >> zhzc[j];
		}
		for(int k=0;k<zhz;k++){
			for(int e=0;e<zhz;e++){
				for(int l=0;l<zhz;l++){
					maxtemp=zhza[k]+zhzb[e]+zhzc[l];
					if(maxtemp>ans) ans=maxtemp;
					
				}
			}
		}
//    	for(int k=0;k<zhz;k++){
//    		if
//		} 
		tnum[i]=ans;
		
	}
	
	for(int i=0;i<t;i++){
		cout << tnum[i] << endl;
	}
} 
