#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+10;
const ll base=37;
const ll mod=1e9+7;
string x,y,u,v;
int n,q,len,nw,ed,ans;
map<pair<string,string>,int> mp;
ll qpow[N],a,b;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;len=x.size();
		mp[{x,y}]++;
	}
	while(q--){
		ans=0;
		cin>>x>>y;
		len=x.size();x=" "+x;y=" "+y;
		nw=1;
		while(nw<=len && x[nw]==y[nw]){
			nw++;
		}
		ed=len;
		while(ed>=1 && x[ed]==y[ed]){
			ed--;
		}
		for(int i=1;i<=nw;i++){
			for(int j=ed;j<=len;j++){
				u=x.substr(i,(j-i+1));
				v=y.substr(i,(j-i+1));
				ans+=mp[{u,v}];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
