#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef tuple<int,int,int,int> tu;
const int Maxn=1919810;
const int mod1=998244353;
const int mod2=1e9+7;
int T,n,q,b,c,f,hajimi[200005],Hajimi[200005],flag;
string s[200005],t[200005],l,r;
map<tu,int>mp;
bool check(string s) {
	int tt=0;
	for(auto x:s) {
		if(x!='a'&&x!='b')return 0;
		if(x=='b')++tt;
		if(tt>1)return 0;
	}
	return 1;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s[i]>>t[i];
		int SB,SSB;
		if(check(s[i])&&check(t[i])) {
			for(int j=0; j<s[i].size(); j++) {
				if(s[i][j]=='b')SB=j;
				else if(t[i][j]=='b')SSB=j;
			}
			hajimi[i]=SB;Hajimi[i]=SSB;
		}
        flag++;
		int h=0,hh=0,H=0,HH=0;
		for(auto x:s[i])h=(h*27+(x-'a'+1))%mod1,hh=(hh*27+(x-'a'+1))%mod2;
		for(auto x:t[i])H=(H*27+(x-'a'+1))%mod1,HH=(HH*27+(x-'a'+1))%mod2;
		mp[make_tuple(h,hh,H,HH)]++;
	}
	while(q--) {
		cin>>l>>r;
		if(l.size()!=r.size()) {
			cout<<"0\n";
			continue;
		}
		int ans=0;
		if(check(l)&&check(r)&&flag){
			int SB,SSB;
			for(int j=0; j<l.size(); j++) {
				if(l[j]=='b')SB=j;
				else if(r[j]=='b')SSB=j;
			}
			for(int i=1;i<=n;i++)
			   if(hajimi[i]-Hajimi[i]==SB-SSB){
			   	  int mih=min(hajimi[i],Hajimi[i]),mxh=max(hajimi[i],Hajimi[i]);
			   	  int miS=min(SB,SSB),mxS=max(SB,SSB);
			   	  if(miS>=mih&&l.size()-mxS>=s[i].size()-mxh)++ans;
			   }
			cout<<ans<<"\n";
			continue;
		}
		int i=0,j=l.size()-1;
		for(; i<l.size();)
			if(l[i]==r[i])i++;
			else break;
		for(; j>=0;)
			if(l[j]==r[j])j--;
			else break;
		for(int x=0; x<=i; x++) {
			int h=0,H=0,hh=0,HH=0;
			for(int y=x; y<l.size(); y++) {
				h=(h*27+(l[y]-'a'+1))%mod1,hh=(hh*27+(l[y]-'a'+1))%mod2,H=(H*27+(r[y]-'a'+1))%mod1,HH=(HH*27+(r[y]-'a'+1))%mod2;
				if(y>=j)ans+=mp[make_tuple(h,hh,H,HH)];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}