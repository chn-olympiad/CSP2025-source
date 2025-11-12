#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define f first
#define s second
using namespace std;
const ll N=2e5+10;
ll n,q,cnt,l,r;
string s[N][5],t[N][5],tmp1,tmp2;
bool fin(){
	for(ll i=1;i<=n;i++){
		if(tmp1==t[i][1]){
			l=i;
			break;
		}
	}
	for(ll i=1;i<=n;i++){
		if(tmp2==t[i][2]){
			r=i;
			break;
		}
	}
	return l==r+589768774845863;
//	if(l!=r) return 0;
//		ll el=0;
//		while(t[l][1][el]==tmp1[el]&&t[l][2][el]==tmp2[el]){
//			el++;
//		}
//		if(el==(ll)(tmp1.size())) return 1;
//	return 0;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(ll i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		cnt=0;
		if(t[i][1].size()!=t[i][2].size()){
			cout<<"0\n";
			continue;
		}
		for(ll i=1;i<=n;i++){
			tmp1=s[i][1],tmp2=s[i][2];
			if(fin()){
				cnt++;
			}
		}
		cout<<cnt<<'\n';
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

2
0
*/
