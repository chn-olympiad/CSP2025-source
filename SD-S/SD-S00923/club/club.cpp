#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N=1e5+10,INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
int n,a[N][4],dt[N];
vector<int> chs[4];
int p=0;
bool cmp(int x,int y){
	return dt[x]<dt[y];
}
void solve(){
	for(int j=0;j<=3;j++)chs[j].clear();
	p=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)cin>>a[i][j];
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])chs[1].pb(i);
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])chs[2].pb(i);
		else chs[3].pb(i);
	}
	for(int j=1;j<=3;j++)
		if(chs[j].size()>n/2)p=j;
	int ans=0;
	for(int i=1;i<=3;i++)
		for(int x:chs[i])
			ans+=a[x][i];
	if(p==0){
		cout<<ans<<'\n';
		return;
	}
	for(int x:chs[p]){
		dt[x]=0;
		for(int j=1;j<=3;j++){
			if(j!=p)dt[x]=max(dt[x],a[x][j]);
		}
		dt[x]=a[x][p]-dt[x];
	}
	sort(chs[p].begin(),chs[p].end(),cmp);
	for(int i=1;i<=chs[p].size()-n/2;i++){
		ans-=dt[chs[p][i-1]];
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
/*
2
10 9 8
4 0 0
pretest passed 14:47
*/
