#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
const int N=5e5+10,M=1e2+10,MOD=1e9+7;
ll n,q,a[N];
string s[2][N];
bool cmp(ll q,ll h){return s[0][q].size()<s[0][h].size();}
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[0][i]>>s[1][i],a[i]=i;
	sort(a+1,a+1+n,cmp);
	while(q--){
		string t0,t1;
		ll ans=0;
		cin>>t0>>t1;
		if(t0.size()!=t1.size()){
			cout<<"0\n";
			continue;
		}
		ll L=-1,R=-1;
		for(int i=0;i<t0.size();i++){
			if(t0[i]!=t1[i]){
				if(L==-1) L=i;
				R=i;
			}
		}
		ll x=R-L+1,idx=n+1;
		L=1,R=n;
		while(L<=R){
			ll mid=(L+R)>>1;
			if(s[0][mid].size()<x) L=mid+1;
			else if(s[0][mid].size()>=x) R=mid-1;
			if(s[0][mid].size()==x) idx=mid;
		}
		for(int i=idx;i<=n;i++){
			ll k=t0.find(s[0][i]);
			if(k<0||k>=t0.size()) continue;
			string x=t0.substr(0,k),z=t0.substr(k+s[0][i].size(),t0.size()-k-s[0][i].size()+1);
			if(x+s[1][i]+z==t1) ans++;
		}
		cout<<ans<<"\n";
	}
}
int main(){
	IOS;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}

