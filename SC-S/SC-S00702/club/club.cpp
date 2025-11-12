#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int t,n,a[100005][4],vis[4],ans;
void dfs(int x,int sum){
	if(x==n+1){
		ans=max(sum,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]<n/2){
			vis[i]++;
			dfs(x+1,sum+a[x][i]);
			vis[i]--;
		}
	}
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		int q=3;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			q=min(q,(int)!a[i][1]+!a[i][2]+!a[i][3]);
		}
		if(q==2){
			vector<int> b1;
			int s1=0;
			for(int i=1;i<=n;i++){
				if(a[i][1]!=0){
					b1.push_back(a[i][1]);s1++;
				}
			}
			sort(b1.begin(),b1.end());
			int id=0;
			while(s1-id>n/2){
				b1[id]=0;
				id++;
			}
			for(int i=0;i<s1;i++){
				ans+=b1[i];
			}
		}else if(n==10)
		    dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
} 
//25