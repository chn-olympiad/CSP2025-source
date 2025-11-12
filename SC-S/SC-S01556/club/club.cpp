#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n,t,a[maxn][4],ans;
void dfs(int d,int s1,int s2,int s3,int sum){
	if(d==n+1){ans=max(ans,sum);return;}
	for(int i=1;i<=3;i++){
		if(i==1&&s1<n/2) dfs(d+1,s1+1,s2,s3,sum+a[d][1]);
		else if(i==2&&s2<n/2) dfs(d+1,s1,s2+1,s3,sum+a[d][2]);
		else if(i==3&&s3<n/2) dfs(d+1,s1,s2,s3+1,sum+a[d][3]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){cin>>a[i][1]>>a[i][2]>>a[i][3];}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}