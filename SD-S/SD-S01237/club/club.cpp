#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define add(u,v,w) tu[(u)].pb({(v),(w)})
#define endl '\n'
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
int n,a[100005][5];
set<pair<pair<pii,pii>,int>>c[5];
int check(int i){
	int siz[]={0,c[1].size(),c[2].size(),c[3].size(),0};
	if(a[i][1]==a[i][2]&&a[i][2]==a[i][3]){
		if(siz[1]==siz[2]&&siz[2]==siz[3])return 1;
		if(siz[1]==siz[2]&&siz[1]<siz[3])return 1;
		if(siz[1]==siz[3]&&siz[1]<siz[2])return 1;
		if(siz[2]==siz[3]&&siz[2]<siz[1])return 2;
		if(siz[1]<siz[2]&&siz[1]<siz[3])return 1;
		if(siz[2]<siz[1]&&siz[2]<siz[3])return 2;
		if(siz[3]<siz[1]&&siz[3]<siz[2])return 3;
	}
	if(a[i][1]==a[i][2]&&a[i][1]>a[i][3])return (siz[1]<siz[2]?1:2);
	if(a[i][1]==a[i][3]&&a[i][1]>a[i][2])return (siz[1]<siz[3]?1:3);
	if(a[i][2]==a[i][3]&&a[i][2]>a[i][1])return (siz[2]<siz[3]?2:3);
	if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])return 1;
	if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])return 2;
	if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		c[1].clear(),c[2].clear(),c[3].clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int j=check(i);
			vector<pii> temp;
			for(int k=1;k<=3;k++){
				if(k!=j)temp.pb({abs(a[i][k]-a[i][j]),k});
			}
			if(temp[0]>temp[1])swap(temp[0],temp[1]);
			c[j].insert({{{temp[0].fi,temp[1].fi},{temp[0].se,temp[1].se}},i});
		}
		int siz[]={0,c[1].size(),c[2].size(),c[3].size(),0};
		for(int i=1;i<=3;i++){
			while(siz[i]>n/2){
				int s=c[i].begin()->se;
				auto x=c[i].begin()->fi;
				c[i].erase(c[i].begin());
				siz[i]--;
				int op=(x.fi.fi==x.fi.se?(siz[x.se.fi]<siz[x.se.se]?x.se.fi:x.se.se):x.se.fi);
				vector<pii> temp;
				for(int k=1;k<=3;k++){
					if(k!=op)temp.pb({abs(a[s][k]-a[s][op]),k});
				}
				if(temp[0]>temp[1])swap(temp[0],temp[1]);
				c[op].insert({{{temp[0].fi,temp[1].fi},{temp[0].se,temp[1].se}},s});
				siz[op]++;
			}
		}
		ll ans=0;
		for(int i=1;i<=3;i++){
			for(auto x:c[i]){
				ans+=a[x.se][i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
