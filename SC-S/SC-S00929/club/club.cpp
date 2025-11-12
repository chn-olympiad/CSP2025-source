#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][4],dp[210][210][210],ans;
bool fl,tr;
priority_queue<int> q1,q2,q3;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		fl=tr=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0) fl=1;
			if(a[i][3]!=0) tr=1;
			ans+=a[i][1];
//			cout<<fl<<" "<<a[i][3]<<"\n";
		}
		if(!fl){
			cout<<ans<<"\n";
			ans=0;
			continue;
		}
		ans=0;
		if(n>200){
			int u=0,v=0,w=0;
			for(int i=1;i<=n;i++){
				int maxn=max(a[i][1],max(a[i][2],a[i][3]));
				if(a[i][1]==maxn) {
					q1.push(max(a[i][2],a[i][3])-a[i][1]);
					u++;
				}
				if(a[i][2]==maxn) {
					q2.push(max(a[i][1],a[i][3])-a[i][2]);
					v++;
				}
				if(a[i][3]==maxn) {
					q3.push(max(a[i][2],a[i][1])-a[i][3]);
					w++;
				}
				ans+=maxn;
			}
//			cout<<u<<" "<<v<<" "<<w<<"\n";
			if(u>n/2){
				u-=n/2;
				while(u--){
					ans+=q1.top();
					q1.pop();
				}
			}
			if(v>=n/2){
				v-=n/2;
				while(v--){
					ans+=q2.top();
					q2.pop();
				}
			}
			if(w>=n/2){
				w-=n/2;
				while(w--){
					ans+=q3.top();
					q3.pop();
				}
			}
			cout<<ans<<"\n";
			ans=0;
			while(!q1.empty()) q1.pop();
			while(!q2.empty()) q2.pop();
			while(!q3.empty()) q3.pop();
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++)
				for(int k=0;k<=min(i-j,n/2);k++){
						if(i-j-k>n/2) continue;
						if(j!=0) dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j-1][k][i-j-k]+a[i][1]);
						if(k!=0) dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k-1][i-j-k]+a[i][2]);
						if(i-j-k!=0) dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k][i-j-k-1]+a[i][3]);
//						cout<<j<<" "<<k<<" "<<i-j-k<<" "<<dp[j][k][i-j-k]<<"\n";
					}
		}
		for(int i=0;i<=n/2;i++)
			for(int j=n/2-i;j<=n/2;j++)
				ans=max(ans,dp[i][j][n-i-j]);
		cout<<ans<<"\n";
		ans=0;
		memset(dp,0,sizeof(dp));
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/