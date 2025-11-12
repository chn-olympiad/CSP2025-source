#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int pos[1<<20+5];
struct point{
	int l,r;
}e[500005];
int cnt;
int dp[500005];
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int sum=0;
	memset(pos,-1,sizeof(pos));
	pos[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum^=a[i];
		if(pos[sum^k]!=-1){
			e[++cnt].l=pos[sum^k]+1;
			e[cnt].r=i;
		}
		pos[sum]=i;
	}
	dp[1]=1;
	for(int i=2;i<=cnt;i++){
		dp[i]=1;
		int l=0,r=i-1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(e[mid].r<e[i].l){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		dp[i]=max(dp[i-1],dp[l]+1);
		ans=max(ans,dp[i]);
		//cout<<e[i].l<<" "<<e[i].r<<" "<<dp[i]<<endl;
	}
	cout<<ans;
}