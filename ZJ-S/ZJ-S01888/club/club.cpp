#include<bits/stdc++.h>
#define ll long long
using namespace std; 
const int MAXN=1e5+10;

int a[MAXN][4];
int n;
ll ans;

void init(){
	memset(a,0,sizeof(a));
	ans=0;
}

int cnt[4];
void dfs(int st,ll ret){
	if(st>=n+1){
		ans=max(ans,ret);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]+1>n/2)continue;
		cnt[i]++;
		dfs(st+1,ret+a[st][i]);
		cnt[i]--;
	}
}

int main(){
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	
	return 0;
}