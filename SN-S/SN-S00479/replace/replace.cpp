#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
const ll MA=2e5+10;
string a[MA][2];
ll siz[MA];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
		siz[i]=a[i][0].size();
	}
	for(ll i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		ll len=s1.size();
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			string s=a[i][0];
			ll x=s1.find(s);
			if(x>=0){
				string ans=s1;
				ans.replace(x,siz[i],a[i][1]);
				/*for(ll j=0;j<x;j++){
					ans+=s1[j];
				}
				for(ll j=x;j<=(x+siz[i]);j++){
					ans+=a[i][1][j];
				}
				for(ll j=(x+siz[i]+1);j<len;j++){
					ans+=s1[j];
				}
				*/
				if(ans==s2) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
