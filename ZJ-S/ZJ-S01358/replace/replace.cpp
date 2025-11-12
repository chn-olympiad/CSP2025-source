#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=2e5+5,M=5e6+5,base=131;
int n,q;
string s[N][2],t[2];
unsigned long long hs[2][M],pw[M];
unsigned long long get(int p,int l,int r){
	return hs[p][r]-hs[p][l-1]*pw[r-l+1];
}
void solve1(){
	while(q--){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<0<<'\n';
			continue ;
		}
		ll len=t[0].size(),l=-1,r=-1,ans=0;
		for(int i=0;i<len;i++){
			if(t[0][i]!=t[1][i]){
				if(l==-1) l=i;
				r=i;
			}
			hs[0][i+1]=hs[0][i]*base+t[0][i]-'a';
			hs[1][i+1]=hs[1][i]*base+t[1][i]-'a';
		}
		for(int i=1;i<=n;i++){
			int le=s[i][0].size();
			unsigned long long h1=0,h2=0;
			for(int j=0;j<le;j++){
				h1=h1*base+s[i][0][j]-'a';
				h2=h2*base+s[i][1][j]-'a';
			}
			int pd=0;
			for(int j=1;j+le-1<=len;j++){
				if(((j-1<=l&&j+le-1-1>=r)||(l==-1&&r==-1))&&get(0,j,j+le-1)==h1&&get(1,j,j+le-1)==h2){
					pd=1;
					break;
				}
			}
			if(pd) ans++;
		}
		cout<<ans<<'\n';
	}
	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	pw[0]=1;
	for(int i=1;i<M;i++) pw[i]=pw[i-1]*base;
	solve1();
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
