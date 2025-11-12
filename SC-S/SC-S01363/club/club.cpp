#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int a[10000000][3],dp[10000000][3],cr[4];

int n,k,mxn=0,b,s;



int main(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		memset(cr,0,sizeof(cr));
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		cin>>k;
		s=0;
		
		for(int j=0;j<k;j++){
			for(int l=0;l<3;l++){
				cin>>a[j][l];
			}
		}
		for(int j=0;j<3;j++) dp[k-1][j]=a[k-1][j];
		int mm;
		for(int j=k-2;j>=0;j--) {
			if(cr[0]<k/2&&dp[j+1][0]>=dp[j+1][1]&&dp[j+1][0]>=dp[j+1][2]) {
				mm=dp[j+1][0];
				cr[0]++;
			}
			else if(cr[1]<k/2&&dp[j+1][1]>=dp[j+1][2]) {
				mm=dp[j+1][1];
				cr[1]++;
			}
			else if(cr[2]<k/2) {
				mm=dp[j+1][2];
				cr[2]++;
			}
			for(int l=0;l<3;l++) {
				if(cr[l]<k/2) dp[j][l]=a[j][l]+mm;
			}
		}
		
		s=max(dp[0][0],max(dp[0][1],dp[0][2]));
		cout<<s<<endl;
	}
} 
