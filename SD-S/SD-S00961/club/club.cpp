#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PII pair<int,int>
#define fi first
#define se second
const int N=1e5+5,mod=998244353;
int n,T;
struct student{
	PII a[4];
}st[N];
vector<int>tab[4];
void solve(){
	cin>>n;
	ll cnt1=0,cnt2=0,cnt3=0,ans=0;
	for(int i=1;i<=3;i++){
		tab[i].clear();
	}
	for(int i=1;i<=n;i++){
		cin>>st[i].a[1].fi>>st[i].a[2].fi>>st[i].a[3].fi;
		for(int j=1;j<=3;j++){
			st[i].a[j].se=j;
		}
		sort(st[i].a+1,st[i].a+4,greater<PII>());
		ans+=st[i].a[1].fi;
		if(st[i].a[1].se==1){
			cnt1++;
			tab[1].pb(st[i].a[1].fi-st[i].a[2].fi);
		}else if(st[i].a[1].se==2){
			cnt2++;
			tab[2].pb(st[i].a[1].fi-st[i].a[2].fi);
		}else if(st[i].a[1].se==3){
			cnt3++;
			tab[3].pb(st[i].a[1].fi-st[i].a[2].fi);
		}
	}
	if(cnt1>n/2){
		sort(tab[1].begin(),tab[1].end());
		for(int i=0;i<cnt1-n/2;i++){
			ans-=tab[1][i];
		}
	}else if(cnt2>n/2){
		sort(tab[2].begin(),tab[2].end());
		for(int i=0;i<cnt2-n/2;i++){
			ans-=tab[2][i];
		}
	}else if(cnt3>n/2){
		sort(tab[3].begin(),tab[3].end());
		for(int i=0;i<cnt3-n/2;i++){
			ans-=tab[3][i];
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	ios;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

