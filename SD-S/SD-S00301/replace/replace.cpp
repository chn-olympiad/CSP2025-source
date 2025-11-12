#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
const ll N=2e5+10; 
const ll MOD1=998244353;
const ll MOD2=1e9+7;
const ll base=29;
const ll INF=2147483647;
ll n,q,S1[N][2],S2[N][2];
string s[N][2],t[N][2];
inline ll ksm1(ll a,ll b){
	a%=MOD1;ll ret=1;
	while(b){if(b&1) ret=ret*a%MOD1;a=a*a%MOD1;b>>=1;}
	return ret;
}
inline ll ksm2(ll a,ll b){
	a%=MOD2;ll ret=1;
	while(b){if(b&1) ret=ret*a%MOD2;a=a*a%MOD2;b>>=1;}
	return ret;
}
void solve_brute(){
	for(ll i=1;i<=n;i++){
		ll lz=s[i][0].size();
		for(ll j=0;j<lz;j++){
			S1[i][0]=S1[i][0]*base%MOD1,S1[i][1]=S1[i][1]*base%MOD1;
			S1[i][0]=(S1[i][0]+s[i][0][j]-'a')%MOD1,S1[i][1]=(S1[i][1]+s[i][1][j]-'a')%MOD1;
			S2[i][0]=S2[i][0]*base%MOD2,S2[i][1]=S2[i][1]*base%MOD2;
			S2[i][0]=(S2[i][0]+s[i][0][j]-'a')%MOD2,S2[i][1]=(S2[i][1]+s[i][1][j]-'a')%MOD2;
		}
	}
	ll ans;
	for(ll i=1;i<=q;i++){
		ans=0;
		if(t[i][0].size()!=t[i][1].size()){cout<<"0\n";continue;}
		ll minnest=INF,maxxest=-INF;
		ll T1[2],T2[2],lz,al=t[i][0].size();
		for(ll j=0;j<al;j++){
			if(t[i][0][j]!=t[i][1][j]){
				minnest=min(minnest,j);
				maxxest=max(maxxest,j);
			}
		}
		for(ll j=1;j<=n;j++){
			lz=s[j][0].size();
			ll minu1=ksm1(base,lz),minu2=ksm2(base,lz);
			T1[0]=T1[1]=T2[0]=T2[1]=0;
			for(ll k=0;k<al;k++){
				T1[0]=T1[0]*base%MOD1,T1[1]=T1[1]*base%MOD1;
				T1[0]=(T1[0]+t[i][0][k]-'a')%MOD1,T1[1]=(T1[1]+t[i][1][k]-'a')%MOD1;
				T2[0]=T2[0]*base%MOD2,T2[1]=T2[1]*base%MOD2;
				T2[0]=(T2[0]+t[i][0][k]-'a')%MOD2,T2[1]=(T2[1]+t[i][1][k]-'a')%MOD2;
				if(k>=lz){
					T1[0]=(T1[0]-minu1*(t[i][0][k-lz]-'a')%MOD1+MOD1)%MOD1;
					T1[1]=(T1[1]-minu1*(t[i][1][k-lz]-'a')%MOD1+MOD1)%MOD1;
					T2[0]=(T2[0]-minu2*(t[i][0][k-lz]-'a')%MOD2+MOD2)%MOD2;
					T2[1]=(T2[1]-minu2*(t[i][1][k-lz]-'a')%MOD2+MOD2)%MOD2;
				}
				if(k>=lz-1){
					if(T1[0]==S1[j][0]&&T2[0]==S2[j][0]&&T1[1]==S1[j][1]&&T2[1]==S2[j][1]){
						if(minnest==INF&&maxxest==-INF) ans++;
						else if(k>=maxxest&&k-lz+1<=minnest) ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;ll L1=0,L2=0;
	for(ll i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		L1+=s[i][0].size();
	}
	for(ll i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		L2+=min(t[i][0].size(),t[i][1].size());
	}
	if(L1*L2<=100000000) solve_brute();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
