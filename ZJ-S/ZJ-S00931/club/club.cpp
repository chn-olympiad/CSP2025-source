#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int n,m,a[100005][3],cnt[3],op[100005];
priority_queue<int>q;
void solve(){
	cin>>n,m=n>>1,ans=cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		int tmp=max({a[i][0],a[i][1],a[i][2]});
		if(tmp==a[i][0]) op[i]=0;
		else if(tmp==a[i][1]) op[i]=1;
		else op[i]=2;
		cnt[op[i]]++,ans+=tmp;
	}
	int t=max({cnt[0],cnt[1],cnt[2]});
	if(t<=m){cout<<ans<<"\n";return;}
	int g;
	if(cnt[0]==t) g=0;
	else if(cnt[1]==t) g=1;
	else g=2;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) if(op[i]==g){
		int t0=-1e9,t1=-1e9,t2=-1e9;
		if(g!=0) t0=a[i][0]-a[i][g];
		if(g!=1) t1=a[i][1]-a[i][g];
		if(g!=2) t2=a[i][2]-a[i][g];
		q.push(max({t0,t1,t2}));
	}
	while(cnt[g]>m) ans+=q.top(),q.pop(),cnt[g]--;
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int Ca;cin>>Ca;while(Ca--)solve();
	return 0;
}