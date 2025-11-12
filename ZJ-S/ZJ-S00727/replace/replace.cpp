#include<bits/stdc++.h>
#define speed_up ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define N 200005
#define M 2025
using namespace std;
typedef long long ll;
ll n,q,ans,mem[M][M];
pair<string,string>s[N];
string t1,t2;
inline void dfs(ll l,ll r){
	mem[l][r]=q;
	string str="",tar="";
	for(ll i=l;i<=r;i++){
		str=str+t1[i];
		tar=tar+t2[i];
	}
	for(ll i=1;i<=n;i++){
		if(s[i].first==str&&s[i].second==tar){
			ans++;break;
		}
	}
	if(l>0&&mem[l-1][r]!=q) dfs(l-1,r);
	if(r<t1.length()-1&&mem[l][r+1]!=q) dfs(l,r+1);
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	speed_up;
	cin>>n>>q;
	for(ll i=1;i<=n;i++) cin>>s[i].first>>s[i].second;
	while(q--){
		cin>>t1>>t2;
		ll l=0,r=t1.length()-1;
		for(ll i=0;i<t1.length();i++){
			if(t1[i]!=t2[i]){
				l=i;break;
			}
		}
		for(ll i=t1.length()-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				r=i;break;
			}
		}
		ans=0;
		dfs(l,r);
		cout<<ans<<"\n";		
	}
	return 0;
}
