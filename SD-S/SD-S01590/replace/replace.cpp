#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+10;
const int base1=131,base2=13331,mod1=998244353,mod2=1e9+7,T=1e9+10;
int n,q,pw1[N],ipw1[N],pw2[N],ipw2[N],lns[N],cnt;
unordered_map<int,int>mp;
inline int qpow(int a,int b,int mod){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod,b>>=1; 
	}
	return res;
}
string s1[N],s2[N],p1,p2;
signed main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//pw1[0]=pw2[0]=ipw1[0]=ipw2[0]=1;
	//for(int i=1;i<N;i++)pw1[i]=pw1[i-1]*base1%mod1,pw2[i]=pw2[i-1]*base2%mod2;
	//ipw1[1]=qpow(base1,mod1-2,mod1),ipw2[1]=qpow(base2,mod2-2,mod2);
	//for(int i=2;i<N;i++)ipw1[i]=ipw1[i-1]*ipw1[1]%mod1,ipw2[i]=ipw2[i-1]*ipw2[1]%mod2;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		cin>>p1>>p2;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s1[i].size()<=p1.size();j++){
				if(p1.substr(j,s1[i].size())==s1[i]){
					string pp="";
					for(int k=0;k<p1.size();k++)if((k<j))pp+=p1[k];
					pp+=s2[i];
					for(int k=0;k<p1.size();k++)if((k>=j+s1[i].size()))pp+=p1[k];
					if(pp==p2)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	/*for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		unsigned long long tmp=0,p,q;
		for(int j=0;j<(int)s1.size();j++)tmp=(tmp*base1+s1[j])%mod1;
		p=tmp,tmp=0;
		for(int j=0;j<(int)s1.size();j++)tmp=(tmp*base2+s1[j])%mod2;
		p+=tmp*T;
		
		tmp=0;
		for(int j=0;j<(int)s2.size();j++)tmp=(tmp*base1+s2[j])%mod1;
		q=tmp,tmp=0;
		for(int j=0;j<(int)s2.size();j++)tmp=(tmp*base2+s2[j])%mod2;
		q+=tmp*T;
		mp[p*(unsigned long long)T+q]++,lns[++cnt]=s1.size();
	}
	sort(lns+1,lns+1+cnt),cnt=unique(lns,lns+1+cnt)-lns-1;
	*/
	/*
	while(q--){
		string p1,p2;
		cin>>p1>>p2;
		int ans=0,l=0,r=p1.size(),ll=0,rr=p2.size();
		if(p1==p2)ans=1;
		while(p1[l]==p2[ll])l++,ll++;
		while(p1[r]==p2[rr])r--,rr--;
		for(int u=1;u<=cnt;u++){
			if(lns[u]>p1.size())continue;
			for(int i=0;i<lns[u];i++){
				h1=(h1*base1+p1[i])%mod1;
				h2=(h2*base2+p1[i])%mod2;
			}
			for(int i=0;i<lns[u]+p2.size()-p1.size();i++){
				hh1=(hh1*base1+p2[i])%mod1;
				hh2=(hh2*base2+p2[i])%mod2;
			}
			for(int i=0;i+lns[u]<p1[u];i++){
				unsigned long long tt=((h2*T+h1)*T+hh2)*T+hh1;
				if(mp.find(tt)!=mp.end())ans+=mp[tt];
				if(i<dt){
					h1=(h1*base1+p1[r+i+1])%mod1;
					h2=(h2*base2+p1[r+i+1])%mod2;
					hh1=(hh1*base1+p2[rr+i+1])%mod1;
					hh2=(hh2*base2+p2[rr+i+1])%mod2;
					
					h1=(h1-ipw1[r-l+1]*p1[l+i])%mod1;
					h2=(h2-ipw2[r-l+1]*p1[l+i])%mod2;
					hh1=(hh1-ipw1[r-l+1]*p2[l+i])%mod1;
					hh2=(hh2-ipw2[r-l+1]*p2[l+i])%mod2;
					
					(h1+=mod1)%=mod1,(hh1+=mod1)%=mod1;
					(h2+=mod2)%=mod2,(hh2+=mod2)%=mod2; 
				}
			}
		}
		cout<<ans<<'\n';
	}*/
	return 0;
}
