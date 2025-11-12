#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fp(s) string ssssss=s;freopen((ssssss+".in").c_str(),"r",stdin);freopen((ssssss+".out").c_str(),"w",stdout);
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define pb push_back
#define inl inline
#define all(x) x.begin(),x.end()
using namespace std;
const int N=1e5+5;
int a[N][5],b[N];
vector<int>g[5];
inl bool cmp(int x,int y){
	return b[x]<b[y];
}
inl void solve(){
	int n,idx=-1,ans=0;
	cin>>n;
	rep(i,1,3) g[i].clear();
	rep(i,1,n)
		rep(j,1,3) cin>>a[i][j];
	rep(i,1,n)
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			g[1].pb(i);
			b[i]=a[i][1]-max(a[i][2],a[i][3]);
			ans+=a[i][1];
		}else if(a[i][2]>=a[i][3]&&a[i][2]>=a[i][1]){
			g[2].pb(i);
			b[i]=a[i][2]-max(a[i][1],a[i][3]);
			ans+=a[i][2];
		}else{
			g[3].pb(i);
			b[i]=a[i][3]-max(a[i][1],a[i][2]);
			ans+=a[i][3];
		}
	rep(i,1,3)
		if((int)g[i].size()>n>>1){
			idx=i;
			break;
		}
//	cout<<ans<<endl;
	if(!~idx){
		cout<<ans<<endl;
		return;
	}
	sort(all(g[idx]),cmp);
	rep(i,0,(int)g[idx].size()-(n>>1)-1) ans-=b[g[idx][i]];
	cout<<ans<<endl;
}
signed main(){
	fp("club");
	fst;
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
} 
