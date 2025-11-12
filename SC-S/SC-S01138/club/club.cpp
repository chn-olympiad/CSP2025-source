#include<bits/stdc++.h>
using namespace std;
int num[4];//每个社团的人数(<=n/2) 
int dp[10005];//满意度 dp[第n个]
int x[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	dp[0]=0;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n;
		memset(num,0,4);
		memset(dp,0,10005);
		memset(x,0,4);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(num[j]<n/2) scanf("%d",&x[j]);	//输入
				else {
					x[j]=0; 
				}
			}
			int maxk=1;
			for(int k=1;k<=3;k++){
				//cout<<x[k]<<' ';//
				if(x[maxk]<x[k]){
					maxk=k;
				} 
				//cout<<"\n"<<x[maxk];
			}
			dp[i]=dp[i-1]+x[maxk];
			//cout<<dp[i-1]<<'+'<<x[maxk]<<"\n";
			num[maxk]+=1; 
			
		}
		cout<<dp[n]<<"\n";
	}
	
	return 0;
}