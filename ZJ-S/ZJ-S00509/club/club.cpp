#include<bits/stdc++.h>
#define maxn 110001
#define int long long
using namespace std;
const int Mod=998244353,inf=1e9+7;
int reduce(int x){return x-(x>=Mod)*Mod;}

int n,a[maxn][3],t[14],id[maxn];
void solve(){
	int ans=0;
	cin>>n;
	for(int i=0;i<3;i++) t[i]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		id[i]=max_element(a[i],a[i]+3)-a[i];
		t[id[i]]++;
		ans+=a[i][id[i]];
	}
	int num=max_element(t,t+3)-t;
	if((t[num]<<1)<=n) return cout<<ans<<'\n',void();
	vector<int>vec;
	for(int i=1;i<=n;i++){
		if(id[i]!=num) continue;
		int cur=inf;
		for(int j=0;j<3;j++) if(j!=num) cur=min(cur,a[i][num]-a[i][j]);
		vec.push_back(cur);
	}
	sort(vec.begin(),vec.end());
	assert(vec.size()>=(t[num]-(n>>1)));
	for(int i=1;i<=t[num]-(n>>1);i++) ans-=vec[i-1];
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
//	init();
	int T=1;
	cin>>T;
	while(T--) solve();
	return 0;
}
