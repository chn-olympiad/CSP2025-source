#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int gro;
const int N=1e6;
int dp[N][4];
int k,k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11;
int sum[N];
int peo[N];
int c,m,p;//代表1,2,3部门 
int s[N];
int t[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>gro;
	
	for(int k=0;k<=gro-1;k++){
	    cin>>peo[k];
	    for(int i=0;i<=peo[k]-1;i++){
		    for(int j=0;j<=2;j++){
			cin>>dp[i][j];
		}
	}
    }
    for(int j=0;j<=gro-1;j++){
    	for(int i=0;i<=peo[j]-1;i++){
    	k1=max(dp[i][0],dp[i][1]);
    	k2=max(dp[i][0],dp[i][2]);
    	k3=max(k1,k2);
    	if(dp[i][0]>dp[i][1]&&dp[i][0]>dp[i][2]) c++;
    	if(dp[i][1]>dp[i][2]&&dp[i][1]>dp[i][0]) m++;
    	if(dp[i][2]>dp[i][1]&&dp[i][2]>dp[i][0]) p++;
		if(c+1<peo[j]/2&&m+1<peo[j]/2&&p+1<peo[j]/2){
            sum[j]+=k3;

		} 
    	k4=max(dp[i+1][0],dp[i+1][1]);
    	k5=max(dp[i+1][0],dp[i+1][2]);
    	k6=max(k4,k5);
    	k7=max(k1+k6,k2+k6);
    	k8=max(k4+k3,k5+k3);
    	if(c+1==peo[j]/2||m+1==peo[j]/2||p+1==peo[j]/2){
			if(k3==dp[i][0]&&k6==dp[i+1][0]) sum[j]+=max(k7,k8);
			if(k3==dp[i][1]&&k6==dp[i+1][1]) sum[j]+=max(k7,k8);
			if(k3==dp[i][2]&&k6==dp[i+1][2]) sum[j]+=max(k7,k8);
		} 	
	}
    }	
    for(int i=0;i<=gro-1;i++){
    	
    	cout<<sum[i]<<" ";
	}	
	return 0;
}    	
	
 

	
	
	
	
	
	
	
	
	
	
	

