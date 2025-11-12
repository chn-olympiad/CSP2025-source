#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define int long long
//#define lli long long
#define pr pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+30,M=5e6+10,mod1=1e9+9,mod2=998244353,m1=101,m2=107;
const int inf=1e18;
int n,q;
pr h[N],hh[N],mi[N];
pr h1[M],h2[M];
string s[N],t[N];
//pr operator -(pr x,pr y){
//	return {x.fi-y.fi+mod,(x.se-y.se+mod)%mod};
//}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;mi[0]={1,1};
	for(int i=1;i<N;i++)mi[i]={mi[i-1].fi*m1%mod1,mi[i-1].se*m2%mod2};
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		for(int j=0;j<s[i].size();j++){
			h[i].fi=(h[i].fi+(s[i][j]-'a')*mi[j].fi)%mod1;
			h[i].se=(h[i].se+(s[i][j]-'a')*mi[j].se)%mod2;
			hh[i].fi=(hh[i].fi+(t[i][j]-'a')*mi[j].fi)%mod1;
			hh[i].se=(hh[i].se+(t[i][j]-'a')*mi[j].se)%mod2;
		}
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
//		if(s1.size()!=s2.size()){
//			cout<<"0\n";
//			continue;
//		}
//		pr t1={0,0},t2={0,0};
//		for(int i=0;i<s1.size();i++){ 
//			t1.fi=(t1.fi+(s1[i]-'a')*mi[i].fi)%mod1;
//			t1.se=(t1.se+(s1[i]-'a')*mi[i].se)%mod2;
//			t2.fi=(t2.fi+(s2[i]-'a')*mi[i].fi)%mod1;
//			t2.se=(t2.se+(s2[i]-'a')*mi[i].se)%mod2;
//			h1[i]=t1;h2[i]=t2;
//		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[i].size()>s1.size())continue;
			for(int j=0;j<=s1.size()-s[i].size();j++){
				int f=1;
				for(int k=0;k<j;k++)if(s1[k]!=s2[k])f=0;
				for(int k=j+s[i].size();k<s1.size();k++)if(s1[k]!=s2[k])f=0;
				for(int k=0;k<s[i].size();k++)if(s[i][k]!=s1[k+j]||t[i][k]!=s2[k+j])f=0;
				ans+=f;
//				if((!j||h1[j-1]==h2[j-1])&&(h1[s1.size()-1]-h1[j+s[i].size()-1]==h2[s1.size()-1]-h2[j+s[i].size()-1])){
//					int o=h1[j+s[i].size()-1]-(j?h1[j-1]:0);
//					if(o==h[i]*mi[j]%mod);
//				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
