#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int maxN=5e6+5;
const int base=13331;
const int M=998244853;
int n,q,ne[maxN];
ll hx[maxN],ba[maxN];
string s,c;
map<pair<int,pair<int,int> >,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>c;
		if(s==c){
			continue;
		}
		int x=0,y=s.size()-1;
		while(s[x]==c[x]){
			x++;
		}
		while(s[y]==c[y]){
			y--;
		}
		ll p=0,q=0,lp=0,lq=0;
		for(int i=x;i<=y;i++){
			p=p*base+s[i]-'a'+1;
			p=p%M;
			q=q*base+c[i]-'a'+1;
			q=q%M;
		}
		mp[{(int)s.size()-y,{p,q}}]++;
	}
	while(q--){
		cin>>s>>c;
		if(s.size()!=c.size()){
			cout<<0<<endl;
			continue;
		}
		int x=0,y=s.size()-1;
		while(s[x]==c[x]){
			x++;
		}
		while(s[y]==c[y]){
			y--;
		}
		ll p=0,q=0;
		for(int i=x;i<=y;i++){
			p=p*base+s[i]-'a'+1;
			p=p%M;
			q=q*base+c[i]-'a'+1;
			q=q%M;
		}
		cout<<mp[{y-x,{p,q}}]<<endl;
	}
	return 0;
}
