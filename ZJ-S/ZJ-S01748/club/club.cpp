#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
int a[100010][4];
int ans;
int cnt[4];
void dfs(int step,int sum){
	if(step>n){
		ans=max(ans,sum);
		return ;
	}
	if(cnt[1]+1<=n/2)cnt[1]++,dfs(step+1,sum+a[step][1]),cnt[1]--;
	if(cnt[2]+1<=n/2)cnt[2]++,dfs(step+1,sum+a[step][2]),cnt[2]--;
	if(cnt[3]+1<=n/2)cnt[3]++,dfs(step+1,sum+a[step][3]),cnt[3]--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}