#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=5e6+10;
int n,m;
string s[2],t[2];
int h[M][2][2],H[N][2][2],L,len[N];
//const int base1=131,base2=1145141,mod1=998244353,mod2=1e8+7;
//int fac[M][2];
//const int Mod[2]={998244353,1e8+7};
map <string,int> mp[2];
void solve(){
	cin>>t[0]>>t[1];
	if(t[1].size()!=t[0].size()) return cout<<"0\n",void();
	L=t[0].size();
	int l,r;
	for(l=0;;l++) if(t[0][l]!=t[1][l]) break;
	for(r=L-1;;r--) if(t[0][r]!=t[1][r]) break;
	int ans=0;
	for(int i=0;i<=l;i++){
		string tmp[2]={"",""};
		for(int j=i;j<L;j++){
			tmp[0]=tmp[0]+t[0][j];
			tmp[1]=tmp[1]+t[1][j];
			if(j>=r){
				if(mp[0].count(tmp[0]) && mp[1].count(tmp[1]) && mp[0][tmp[0]]==mp[1][tmp[1]]) ans++;
			}
		}
	}
	cout<<ans<<"\n";
//	L=t[1].size();
//	h[0][0][0]=h[0][1][0]=h[0][0][1]=h[0][1][1]=0;
//	for(int i=1;i<=L;i++) h[i][0][0]=(h[i-1][0][0]*base1%mod1+(int)t[0][i-1])%mod1,cout<<h[i][0][0]<<" ";
//	for(int i=1;i<=L;i++) h[i][0][1]=(h[i-1][0][1]*base2%mod2+(int)t[0][i-1])%mod2;
//	for(int i=1;i<=L;i++) h[i][1][0]=(h[i-1][1][0]*base1%mod1+(int)t[1][i-1])%mod1;
//	for(int i=1;i<=L;i++) h[i][1][1]=(h[i-1][1][1]*base2%mod2+(int)t[1][i-1])%mod2;
//	cout<<"\n";
//	cout<<(h[4][0][0]-h[2][0][0]*fac[2][0]%Mod[0]+Mod[0])%Mod[0]<<" ";
//	int ans=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j+len[i]-1<=L;j++){
//			bool fg=1;
//			for(int x=0;x<=1;x++)
//				for(int y=0;y<=1;y++)
//					fg&=(H[i][x][y]*fac[j-1][y]%Mod[y]==(h[j+len[i]-1][x][y]-h[j-1][x][y]*fac[len[i]][y]%Mod[y]+Mod[y])%Mod[y]);
//			if(fg) cout<<i<<" "<<j<<" ",ans++;
//		}
//	}
//	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
//	fac[0][0]=fac[0][1]=1;
//	for(int i=1;i<M;i++) fac[i][0]=fac[i-1][0]*base1%mod1,fac[i][1]=fac[i-1][1]*base2%mod2;
//	cout<<fac[2][0]<<" ";
	for(int i=1;i<=n;i++){
		cin>>s[0]>>s[1];
		mp[0][s[0]]=i;
		mp[1][s[1]]=i;
//		len[i]=s[0].size();
//		H[i][0][0]=H[i][0][1]=H[i][1][0]=H[i][1][1]=0;
//		for(int j=1;j<=len[i];j++) H[i][0][0]=(H[i][0][0]*base1+(int)s[0][j-1])%mod1;
//		for(int j=1;j<=len[i];j++) H[i][0][1]=(H[i][0][1]*base2+(int)s[0][j-1])%mod2;
//		for(int j=1;j<=len[i];j++) H[i][1][0]=(H[i][1][0]*base1+(int)s[1][j-1])%mod1;
//		for(int j=1;j<=len[i];j++) H[i][1][1]=(H[i][1][1]*base2+(int)s[1][j-1])%mod2;
	}
//	cout<<H[2][0][0]<<"\n";
	for(;m--;) solve();
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
