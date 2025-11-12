#include<bits/stdc++.h>
#define ll int
#define weil '\n'
#define pb(x) push_back(x)
using namespace std;
mt19937_64 rd(time(0));
const ll N=5e6+5;
ll n,ch[N][30],tot,ci;
map<pair<ll,string> ,ll> wei,dao;
void add(string x,string y){
	ll len=x.size(),p=1;string ss;ss.clear();
	for(int j=0;j<len;j++){
		ll yi=x[j]-'a',er=y[j]-'a';ss+=y[j];
		if(!ch[p][yi]){
			ch[p][yi]=++tot;
		}
		p=ch[p][yi];dao[make_pair(p,ss)]++;
	}
	wei[make_pair(p,y)]++;
	//cout<<p<<' '<<y<<endl;
}
ll find(string s,string t,ll l,ll r){
	ll p=1,len=s.size(),now=0;string ss;ss.clear();
	for(int i=l;i<len;i++){
		ss+=t[i];
		ll yi=s[i]-'a',er=t[i]-'a';
		if(i<=r&&(!ch[p][yi]||!dao[make_pair(ch[p][yi],ss)])){
			return 0;
		}
		if(!ch[p][yi]||!dao[make_pair(ch[p][yi],ss)])return now;
		p=ch[p][yi];
		if(i>=r){
			now+=wei[make_pair(p,ss)];
		}
	}
	return now;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll q,sum=0;
	cin>>n>>q;tot=1;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
	//	if(s1==s2)sum++;
		add(s1,s2);
	}
	ci=0;
	while(q--){
		string s,t;
		cin>>s>>t;
		ll len=s.size(),l=0,r=-1;
		for(int i=0;i<len;i++){
			if(s[i]!=t[i]){
				l=i;break;
			}
		}
		for(int i=len-1;i>=0;i--){
			if(s[i]!=t[i]){
				r=i;break;
			}
		}
		ll ans=0;
	
		//cout<<l<<' '<<r<<endl;
		for(int i=0;i<=l;i++){
			ans+=find(s,t,i,r);
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%

