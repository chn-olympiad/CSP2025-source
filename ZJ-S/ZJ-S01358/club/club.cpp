#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=1e5+5;
int n;
bool b[N];
pii a[N][3];
void solve(){
	ll ans=0,cnt0=0,cnt1=0,cnt2=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		b[i]=0;
		for(int j=0;j<3;j++) cin>>a[i][j].fi,a[i][j].se=j;
		sort(a[i],a[i]+3);
		ans+=a[i][2].fi;
		if(a[i][2].se==0) cnt0++;
		else if(a[i][2].se==1) cnt1++;
		else cnt2++;
	}
	if(cnt0>n/2){
		vector<pii> v;
		for(int i=1;i<=n;i++){
			if(a[i][2].se==0) v.push_back(make_pair(a[i][2].fi-a[i][1].fi,i));
		}
		sort(v.begin(),v.end());
		for(int i=0;i<cnt0-n/2;i++) ans-=v[i].fi;
	}
	if(cnt1>n/2){
		vector<pii> v;
		for(int i=1;i<=n;i++){
			if(a[i][2].se==1) v.push_back(make_pair(a[i][2].fi-a[i][1].fi,i));
		}
		sort(v.begin(),v.end());
		for(int i=0;i<cnt1-n/2;i++) ans-=v[i].fi;
	}
	if(cnt2>n/2){
		vector<pii> v;
		for(int i=1;i<=n;i++){
			if(a[i][2].se==2) v.push_back(make_pair(a[i][2].fi-a[i][1].fi,i));
		}
		sort(v.begin(),v.end());
		for(int i=0;i<cnt2-n/2;i++) ans-=v[i].fi;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}

