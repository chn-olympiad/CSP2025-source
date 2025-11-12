#include<bits/stdc++.h>
using namespace std;
int a[100010][10];
struct node{
	int zhi,i,wei;
}dp[300030];
bool cmp(node x,node y){
	return x.zhi<y.zhi;
}
int cnt[5];
bool vis[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			dp[(i-1)*3+1].zhi=a[i][1];
			dp[(i-1)*3+1].i=i;
			dp[(i-1)*3+1].wei=1;
			
			dp[(i-1)*3+2].zhi=a[i][2];
			dp[(i-1)*3+2].i=i;
			dp[(i-1)*3+2].wei=2;
			
			dp[(i-1)*3+3].zhi=a[i][3];
			dp[(i-1)*3+3].i=i;
			dp[(i-1)*3+3].wei=3;
			vis[i]=0;
	    }
	    cnt[1]=cnt[2]=cnt[3]=0;
	    sort(dp+1,dp+1+3*n,cmp);
	    long long sum=0;
	    for(int i=1;i<=3*n;i++){
	    	if(cnt[dp[i].wei]<n/2 && !vis[dp[i].i]){
	    		vis[dp[i].i]=1;
	    		sum+=dp[i].zhi;
	    		cnt[dp[i].wei]++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
