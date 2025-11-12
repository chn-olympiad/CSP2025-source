#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N][4];
int n;
long long ans=0;
map<tuple<int,int,int>,long long>mp;
void dfs(int now,int cnt1,int cnt2,int cnt3,long long sum){
	if(now==n+1){
		ans=max(ans,sum);
		return;
	}
	if(cnt1<=n/2&&cnt1+cnt2+cnt3-2<=n){
		long long &x=mp[make_tuple(cnt1+1,cnt2,cnt3)];
		if(x==0||x<sum+a[now][1]){
			dfs(now+1,cnt1+1,cnt2,cnt3,sum+a[now][1]);
			x=sum+a[now][1];	
		}
	}
	if(cnt2<=n/2&&cnt1+cnt2+cnt3-2<=n){
		long long &x=mp[make_tuple(cnt1,cnt2+1,cnt3)];
		if(x==0||x<sum+a[now][2]){
			dfs(now+1,cnt1,cnt2+1,cnt3,sum+a[now][2]);	
			x=sum+a[now][2];	
		}
	}
	if(cnt3<=n/2&&cnt1-1+cnt2-1+cnt3<=n){
		long long &x=mp[make_tuple(cnt1,cnt2,cnt3+1)];
		if(x==0||x<sum+a[now][3]){
			dfs(now+1,cnt1,cnt2,cnt3+1,sum+a[now][3]);	
			x=sum+a[now][3];	
		}
	}
	return;
}
int b[N];
void solve(){
	cin>>n;
	int flaga=true,flagb=true,flagc=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		if(a[i][2]==0||a[i][3]==0)flaga=false;
	}
	if(flaga){
		for(int i=1;i<=n;i++)b[i]=a[i][1];
		sort(b+1,b+n+1);
		ans=0;
		for(int i=n;i>=n/2+1;i--)ans+=b[i];
		cout<<ans<<endl;
		return;
	}
	ans=0;
	for(auto it=mp.begin();it!=mp.end();it++)it->second=0;
	dfs(1,1,1,1,0);
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
