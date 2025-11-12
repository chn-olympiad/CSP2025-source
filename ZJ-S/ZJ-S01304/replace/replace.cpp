#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
const int M=5e6+5;
const int mod=999995093;
const int B=999996407;
ll p[M];
struct Hs{
	vector<ll>h;
	ll H;
	Hs(){}
	Hs(const string&s){
		int len=s.size();
		h.resize(len+1,0ll);
		h[0]=1;
		for(int i=1;i<=len;i++){
			h[i]=(h[i-1]*B%mod+(s[i-1]-'a'+1))%mod;
		}
		H=h[len];
	}
	ll Query(int l,int r){
		if(l>r)return 0;
		return (h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod;
	}
};
int n,q;
string s[N][2],t[N][2];
Hs c[N][2],d[N][2];
pair<ll,ll>b[N];
ll qpow(ll a,ll b){
	ll ans=1,base=a;
	while(b){
		if(b&1)ans=ans*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	p[0]=1;
	for(int i=1;i<M;i++)p[i]=p[i-1]*B%mod;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=n;i++){
		c[i][0]=Hs(s[i][0]);c[i][1]=Hs(s[i][1]);
	}
	for(int i=1;i<=q;i++)cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=q;i++){
		d[i][0]=Hs(t[i][0]);d[i][1]=Hs(t[i][1]);
	}
	for(int i=1;i<=n;i++)b[i]={c[i][0].Query(1,s[i][0].size()),c[i][1].Query(1,s[i][1].size())};
	sort(b+1,b+n+1);
	for(int i=1;i<=q;i++){
		int len=t[i][0].size();
		int sum=0;
		ll hd2=d[i][1].Query(1,len);
		int pre=n,suf=1;
		for(int j=1;j<=len;j++)if(t[i][0][j-1]!=t[i][1][j-1])suf=j;
		for(int j=len;j>=1;j--)if(t[i][0][j-1]!=t[i][1][j-1])pre=j;
		for(int L=1;L<=pre;L++)
			for(int R=max(suf,L);R<=len;R++) {
				pair<ll,ll>u;
				u.first=d[i][0].Query(L,R);
				ll A=d[i][0].Query(1,L-1)*p[len-L+1]%mod;
				ll C=d[i][0].Query(R+1,len);
				u.second=(hd2-A+mod-C+mod)%mod*qpow(p[len-R],mod-2)%mod;
				sum+=upper_bound(b+1,b+n+1,u)-lower_bound(b+1,b+n+1,u);
			}	
		
		if(d[i][0].Query(1,len)==d[i][1].Query(1,len))sum++; // null string
		cout<<sum<<"\n";
	}	
	return 0;
}