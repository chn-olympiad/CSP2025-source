#include<bits/stdc++.h>
using namespace std;
int a[500010][22]={0};
int dp[500010]={0};
int k[20]={0};
int n,k2;
int iii=1;
int ma=-1;
/*
int x_or(int l,int r){
	for(int i=1;i<=n;i++){
		if((a[r][i]-a[l-1][i])%2!=k[i]) return 0;
	}
	return 1;
}
*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k2;
	while(k2>0){
		k[iii]=k2%2;
		//cout<<k[iii];
		k2/=2;
		iii++;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		iii=1;
		while(iii<20){
			a[i][iii]=a[i-1][iii]+x%2;
			//cout<<a[i][iii]<<' ';
			x/=2;
			iii++;
		}
		//cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int f=1;
			for(int ii=1;ii<20;ii++){
				if((a[i][ii]-a[j-1][ii])%2!=k[ii]) f=0;
				
				//if((a[i][ii]-a[j-1][ii])%2!=k[ii]) cout<<ii<<' '<<a[i][ii]<<' '<<a[j-1][ii]<<' '<<k[ii]<<"   ";
			}
			if(f==1) dp[i]=max(dp[i],dp[j-1]+1);
			//cout<<f<<' ';
		}
		//cout<<dp[i]<<' ';
		ma=max(ma,dp[i]);
	}
	cout<<ma;
	return 0;
}
