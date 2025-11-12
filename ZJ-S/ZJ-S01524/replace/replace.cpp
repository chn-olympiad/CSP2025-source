#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[10005],ss[10005],t,tt,ttt;
ll ans,n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
	}
	for(ll i=1;i<=q;i++){
		cin>>t>>tt;
		ans=0;
		for(ll k=1;k<=n;k++){
			ll siz=s[k].size();
			for(ll j=0;j<t.size()-siz+1;j++){
				ttt=t;
				for(ll l=j;l<=j+siz-1;l++){
					ttt[l]=ss[k][l-j];
				}
				if(ttt==tt)ans++;
			
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
