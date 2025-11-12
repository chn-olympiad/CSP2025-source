#include<bits/stdc++.h>
using namespace std;
int n,t,dp[1010],value[1010][1010],temp,temp1,sum,temp11[1010];
int bol[1010];//标记是否纳入过 
int ans[1010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){//数据组数	
		cin>>n;//人数 
		sum=0; 	 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>value[i][j];
				if(j==1){
					temp11[i]=value[i][j];
				}		
			}
		}
		//输入满意度 
		for(int i=1;i<=n;i++){
			temp=max(temp,value[i][2]);
			temp1=max(temp1,value[i][3]);
		}
		if(temp==temp1 && temp==0 && temp1==0){
			sort(temp11+1,temp11+1+n);
			for(int i=n;i>n/2;i--){
				sum+=temp11[i];
			}
			cout<<sum<<endl;
		}
		//特殊点 
		else{
			memset(bol,0,n); 
			memset(dp,0,n);
			for(int j=1;j<=3;j++){//社团编号 最大为3 
				memset(dp,0,1010);//初始化 
				for(int i=1;i<=n;i++){//新成员编号 	
					for(int k=n/2;k>=1;k--){
						if(bol[i]==0 && dp[k]<dp[k-1]+value[i][j]){//k是背包容量 
							dp[k]=max(dp[k],dp[k-1]+value[i][j]);
							bol[i-1]=0;
							bol[i]==1;
						}			
					}
				}
				ans[j]=dp[n/2];
			//	cout<<ans[j]<<endl;
			}
			for(int i=1;i<=3;i++){
				sum+=ans[i];
			}
			cout<<sum<<endl;
		}	
	}
	return 0;
}

