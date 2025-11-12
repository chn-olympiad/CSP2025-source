#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100005][4],ren[4],ans;
void dfs(int x,int sum1,int sum2,int sum3){
	if(x>n){
		ans=max(sum1+sum2+sum3,ans);
		return;
	}
	if(ren[1]<n/2){
		ren[1]++;
		dfs(x+1,sum1+a[x][1],sum2,sum3);
		ren[1]--;
	}
	if(ren[2]<n/2){
		ren[2]++;
		dfs(x+1,sum1,sum2+a[x][2],sum3);
		ren[2]--;
	}
	if(ren[3]<n/2){
		ren[3]++;
		dfs(x+1,sum1,sum2,sum3+a[x][3]);
		ren[3]--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		ans=-2e9;
		dfs(1,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
