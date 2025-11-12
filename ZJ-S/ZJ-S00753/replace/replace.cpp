#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=200010;
ll n,m;
pair<string,string> s[maxn];
string ft,st;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	for(;m>0;m--){
		cin>>ft>>st;
		ll len=ft.size(),ans=0;
	//	cout<<len<<" ";
		for(ll i=1;i<=n;i++){
			ll l2=s[i].first.size();
		//	cout<<l2<<" ";
			for(ll j=0;j<=len-l2;j++){
				ll fflag=1,sflag=1,t=0;
				for(ll k=j;k<j+l2;k++){
					if(ft[k]!=s[i].first[t++]){
						fflag=0;
						break;
					}
				}
				if(fflag==1){
					string tmp;
					for(ll k=0;k<len;k++){
						if(k==j){
							tmp+=s[i].second;
							k+=l2-1;
							continue;
						}
						tmp+=ft[k];
					}
				//	cout<<tmp<<"\n";
					ll l3=tmp.size(),l4=st.size();
					if(l3!=l4) continue;
					for(ll k=0;k<l3;k++){
						if(tmp[k]!=st[k]){
							sflag=0;
							break;
						} 
					}
					if(sflag==1){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	//God bless me that I can steal some scores.\O/\O/\O/
	return 0;
}
