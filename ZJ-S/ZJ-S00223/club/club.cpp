#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define endl '\n'
#define pb push_back

const int N=1e5+5;

int n;

void solver_008(){
	int ans=0;
	vector<int> v[5];
	cin>>n;
	rep(i,1,n){
		pii a[5];
		rep(j,1,3)cin>>a[j].x,a[j].y=j;
		sort(a+1,a+3+1);
		v[a[3].y].pb(a[3].x-a[2].x);
		ans+=a[3].x;
	}
	rep(i,1,3)if(v[i].size()>n/2){
		sort(v[i].begin(),v[i].end());
		rep(j,1,v[i].size()-n/2)
			ans-=v[i][j-1];
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int __T;cin>>__T;
	while(__T--){
		solver_008();
	}
	return 0;
}
