#include<bits/stdc++.h>
using namespace std;
int a[100010][5];
int ans=0;
int n;
void dfs(int d,int cnt1,int cnt2,int cnt3,int sum){
	if(d==n){
		ans=max(sum,ans);
		return ;
	}
	
	if(cnt1<n/2) dfs(d+1,cnt1+1,cnt2,cnt3,sum+a[d+1][1]);
	if(cnt2<n/2) dfs(d+1,cnt1,cnt2+1,cnt3,sum+a[d+1][2]);
	if(cnt3<n/2) dfs(d+1,cnt1,cnt2,cnt3+1,sum+a[d+1][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		
		dfs(0,0,0,0,0);
		cout<<ans<<"\n";
		ans=0;
	}
    return 0;
}