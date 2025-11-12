#include <bits/stdc++.h>
using namespace std;
#define int long long
const int B=2333,mod=998244353,N=400005;
int n,q,tot,hs[N],ht[N],p[N],mx;
string s,t;
vector<int> g[N];
unordered_map<int,int> mp;
int get(int x){
	if(!mp[x]){
		mp[x]=++tot;
		return mp[x];
	}
	return mp[x];
}
int get22(int x){
	if(!mp[x]){
		return -1;
	}
	return mp[x];
}
int getss(int l,int r){
	return (hs[r]-hs[l-1]*p[r-l+1]%mod+mod)%mod;
} 
int gettt(int l,int r){
	return (ht[r]-ht[l-1]*p[r-l+1]%mod+mod)%mod;
} 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>n>>q; 
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		int h=0,h2=0;
		for(int j=0;j<(int)s.size();j++) h=(h*B+s[j])%mod;
		for(int j=0;j<(int)t.size();j++) h2=(h2*B+t[j])%mod;
		h=get(h),h2=get(h2); 
		g[h].push_back(h2);
		mx=max(mx,(int)s.size());
	}
	p[0]=1;
	for(int i=1;i<N;i++) p[i]=p[i-1]*B%mod;
	while(q--){
		int ans=0;
		cin>>s>>t;
		int len=s.size();
		s='#'+s,t='#'+t;
		for(int i=1;i<=len;i++)
			hs[i]=(hs[i-1]*B+s[i])%mod;
		for(int i=1;i<=len;i++)
			ht[i]=(ht[i-1]*B+t[i])%mod;
		for(int i=1;i<=len;i++){
			if(i!=1&&s[i-1]!=t[i-1]) break;
			for(int j=min(len,i+mx-1);j>=i;j--){
				if(j!=len&&s[j+1]!=t[j+1]) break;
				int hh1=getss(i,j),hh2=gettt(i,j);
			//	cout<<i<<" "<<j<<" "<<hh1<<" "<<hh2<<endl;
				int tmp=get22(hh1),tmp2=get22(hh2);
				if(tmp==-1||tmp2==-1) continue;
				for(int kk=0;kk<(int)g[tmp].size();kk++){
					ans+=(g[tmp][kk]==tmp2);
				}
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
}
