#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;
int t,n,m;
int d[N][5];
int maxn=0;
void dfs(int k,int cnt1,int cnt2,int cnt3,int sum){
	if(k==n+1){
		maxn=max(maxn,sum);
		return;
	}
	if(cnt1<m)dfs(k+1,cnt1+1,cnt2,cnt3,sum+d[k][1]);
	if(cnt2<m)dfs(k+1,cnt1,cnt2+1,cnt3,sum+d[k][2]);
	if(cnt3<m)dfs(k+1,cnt1,cnt2,cnt3+1,sum+d[k][3]);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		maxn=0;
		for(int i=1;i<=n;i++)cin>>d[i][1]>>d[i][2]>>d[i][3];
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<maxn<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				maxn+=max(max(d[i][1],d[i][2]),d[i][3]);
			}
			cout<<maxn<<endl;
		}
	}
	return 0;
}
