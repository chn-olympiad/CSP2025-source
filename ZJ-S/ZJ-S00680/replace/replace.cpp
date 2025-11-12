#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second
const int N=2e5+9,L=2e6+9,bs=131,mod=1e9+9;
int n,q,hs1[L],hs2[L],pw[L];string s1[N],s2[N];vector<int>hsh1[N],hsh2[N];map<pii,vector<piii>>mp;
int vals1(int x,int l,int r){return l?(hsh1[x][r]+mod-1ll*hsh1[x][l-1]*pw[r-l+1])%mod:hsh1[x][r];}
int vals2(int x,int l,int r){return l?(hsh2[x][r]+mod-1ll*hsh2[x][l-1]*pw[r-l+1])%mod:hsh2[x][r];}
int valt1(int l,int r){return l?(hs1[r]+mod-1ll*hs1[l-1]*pw[r-l+1])%mod:hs1[r];}
int valt2(int l,int r){return l?(hs2[r]+mod-1ll*hs2[l-1]*pw[r-l+1])%mod:hs2[r];}
int main(){freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(cin.tie(cout.tie()));
	cin>>n>>q;pw[0]=1;
	if(q==1)return puts("0"),0;
	for(int i=1;i<=L;i++)pw[i]=1ll*pw[i-1]*bs%mod;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];int hs=0;
		for(char j:s1[i])hs=(1ll*hs*bs+j)%mod,hsh1[i].pb(hs);
		hs=0;
		for(char j:s2[i])hs=(1ll*hs*bs+j)%mod,hsh2[i].pb(hs);
		for(int j=0;j<s1[i].size();j++)for(int jj=j;jj<s1[i].size();jj++)mp[(pii){vals1(i,j,jj),vals2(i,j,jj)}].pb({i,{j,jj}});
		
	}
	for(string t1,t2;q--;){
		cin>>t1>>t2;
		if(t1.size()^t2.size()){puts("0");continue;}
		int l=-1,r=-1;
		for(int i=0;i<t1.size();i++){
			if(l==-1&&t1[i]!=t2[i])l=i;
			if(t1[i]!=t2[i])r=i;
		}hs1[0]=t1[0],hs2[0]=t2[0];
		for(int i=1;i<t1.size();i++)hs1[i]=(1ll*hs1[i-1]*bs+t1[i])%mod;
		for(int i=1;i<t2.size();i++)hs2[i]=(1ll*hs2[i-1]*bs+t2[i])%mod;
		int val1=valt1(l,r),val2=valt2(l,r),ans=0;
		if(mp.count({val1,val2})){
			vector<piii>tmp=mp[{val1,val2}];
			for(auto x:tmp){
				int i=x.fi,l1=x.se.fi,r1=x.se.se;
				//cerr<<i<<'\n';
				int flg1=!l1||vals1(i,0,l1-1)==vals2(i,0,l1-1)&&vals1(i,0,l1-1)==valt1(l-l1,l-1);
				//cerr<<0<<' '<<l1-1<<"vs"<<l-l1<<' '<<l-1<<'\n';
				int len=s1[i].size();
				int flg2=r1==len-1||vals1(i,r1+1,len-1)==vals2(i,r1+1,len-1)&&vals1(i,r1+1,len-1)==valt1(r+1,r+len-r1-1);
				//cerr<<0<<' '<<l1-1<<"vs"<<l-l1<<' '<<l-1<<'\n';
				if(flg1&&flg2)++ans;
			}cout<<ans<<'\n';
		}else puts("0");
	}
	return 0;
}
