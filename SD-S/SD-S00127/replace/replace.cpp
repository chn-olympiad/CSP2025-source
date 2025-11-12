#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=205;
const ll base=131,mod=998244353;
ll hs[5][N];
ll mibas[N],inv[N];
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void geths(int idx,string s){
	memset(hs[idx],0,sizeof hs[idx]);
	hs[idx][0]=0;
	for(int i=1;i<s.length();i++){
		hs[idx][i]=(hs[idx][i-1]*base+s[i])%mod;
	}
}
ll Hs(int idx,int l,int r){
	return (hs[idx][r]-hs[idx][l-1]*mibas[(r-l+1)]%mod+mod)%mod;
}
string s[N],t[N];
int len[N];
string u,v;
int n,q,nxt[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	mibas[0]=1;
	for(int i=1;i<=200;i++){
		mibas[i]=mibas[i-1]*base%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		len[i]=s[i].length();
		s[i]=' '+s[i];t[i]=' '+t[i];
	}
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		int cnt=0;
		int m=u.length();
		u=' '+u;v=' '+v;
		int mxp=0,mnp=m+1;
		for(int j=1;j<=m;j++){
			if(u[j]!=v[j]){
				mxp=j-1;
				break;
			}
		}
		for(int j=m;j>=1;j--){
			if(u[j]!=v[j]){
				mnp=j+1;
				break;
			}
		}
		geths(1,u);geths(2,v);
		for(int j=1;j<=n;j++){
			geths(3,s[j]);geths(4,t[j]);
			for(int k=1;k<=m;k++){
				if(mxp+1<k||k+len[j]<mnp)continue;
				if(Hs(1,k,k+len[j]-1)==Hs(3,1,len[j])&&Hs(2,k,k+len[j]-1)==Hs(4,1,len[j])){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

