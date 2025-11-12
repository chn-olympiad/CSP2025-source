#include<bits/stdc++.h>
typedef unsigned long long ull;
#define int long long
#define mod 1000000007
#define bas 20090803
using namespace std;
int n,q,k[200005][3],f[5000006];
ull kk[200005][3],ff[5000005];
vector<int>l1,l2;
vector<ull>ll1,ll2;
bool vis[200005];
string s[200005][3],t1,t2;
int g(vector<int> &u,int l,int r){
	return ((u[r]-u[l-1]*f[r-l+1]%mod)%mod+mod)%mod;
}
ull oo(vector<ull> &u,int l,int r){
	return u[r]-u[l-1]*ff[r-l+1];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr);
	cin>>n>>q;f[0]=1;ff[0]=1;
	for(int i=1;i<=5000000;i++)ff[i]=ff[i-1]*bas,f[i]=f[i-1]*bas%mod;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		if(s[i][1]==s[i][2])vis[i]=1;
		int t=s[i][1].size();
//		k[i][1].resize(s[i][1].size()+1);
//		k[i][2].resize(s[i][2].size()+1);
		for(int j=1;j<=t;j++){
			k[i][1]=(k[i][1]*bas%mod+s[i][1][j-1])%mod;
			kk[i][1]=kk[i][1]*bas+s[i][1][j-1];
			k[i][2]=(k[i][2]*bas%mod+s[i][2][j-1])%mod;
			kk[i][2]=kk[i][2]*bas+s[i][2][j-1];
		}//cerr<<'\n';
	}
	while(q--){
		cin>>t1>>t2;int t=t1.size();
		l1.resize(t1.size()+1);
		l2.resize(t2.size()+1);
		ll1.resize(t1.size()+1);
		ll2.resize(t2.size()+1);
		for(int j=1;j<=t;j++){
			l1[j]=(l1[j-1]*bas%mod+t1[j-1])%mod;
			l2[j]=(l2[j-1]*bas%mod+t2[j-1])%mod;
			ll1[j]=(ll1[j-1]*bas+t1[j-1]);
			ll2[j]=(ll2[j-1]*bas+t2[j-1]);
		}int ans=0,l=0,r=0;
		for(l=0;l<(int)t1.size();l++)if(t1[l]!=t2[l])break;
		for(r=(int)t1.size()-1;r>=0;r--)if(t1[r]!=t2[r])break;
		l++,r++;
		for(int i=1;i<=n;i++){
			int h=s[i][1].size();
			if(vis[i]||r-l+1>h)continue;
			for(int j=max(1ll,r-h+1);j<=min(t-h+1,l);j++){
				if(k[i][1]==g(l1,j,j+h-1)&&k[i][2]==g(l2,j,j+h-1)){
					if(kk[i][1]==oo(ll1,j,j+h-1)&&kk[i][2]==oo(ll2,j,j+h-1))ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}