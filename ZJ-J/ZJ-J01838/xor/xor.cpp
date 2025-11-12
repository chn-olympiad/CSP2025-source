#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
const int mx=5e5+10;
int n,k;
int a[mx];
int sum[mx];
int dp[mx];
map<int,vector<int> > mp;

int nxor(int x,int y){
	int res=0;
	for(int i=0;i<=21;i++){
		int nx=x&(1<<i),ny=y&(1<<i);
		nx=(nx>>i),ny=(ny>>i);
		//cout<<nx<<" "<<ny<<endl;
		if(nx==0&&ny==0) continue;
		if(nx==1&&ny==1) continue;
		res+=(1<<i);
	}
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sum[1]=a[1];
	mp[sum[1]].push_back(1);
	mp[0].push_back(0);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
		mp[sum[i]].push_back(i);
	} 
	
	for(int i=1;i<=n;i++){
		int tmp=nxor(sum[i],k);
		//cout<<sum[i]<<" "<<"tmp:"<<tmp<<endl;
		dp[i]=dp[i-1];
		//cout<<mp[tmp].size()<<endl;
		int l=0,r=mp[tmp].size()-1,mid;
		int ans=-1;
		while(l<=r){
			mid=(l+r)/2;
			if(mp[tmp][mid]>=i) r=mid-1;
			else{
				ans=max(ans,mid);
				l=mid+1;
			}
		}
		if(ans==-1) continue;
		dp[i]=max(dp[mp[tmp][ans]]+1,dp[i]);
//		for(int j=mp[tmp].size()-1;j>=0;j--){
//			//cout<<mp[tmp][j]<<" ";
//			if(mp[tmp][j]<i){
//				dp[i]=max(dp[mp[tmp][j]]+1,dp[i]);
//				break;
//			}
//		} 
	}
 	cout<<dp[n]<<endl;
  	return 0;
}
