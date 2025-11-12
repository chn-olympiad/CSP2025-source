// 夏菁阳 SN-S00138 西安高新第一中学
#include<bits/stdc++.h>
#define il inline
using namespace std;

constexpr int MAXN=505,MOD=998244353;
int n,m,c[MAXN],dp[MAXN][MAXN],ans;
string s;
il void add(int&x,int y){
	x=x+y>=MOD?x+y-MOD:x+y;
}

namespace sa{
	int p[11];
	il int main(){
		iota(p+1,p+n+1,1);
		do{
			int fk=0,lu=0;
			for(int i=1;i<=n;i++){
				if(fk>=c[p[i]]) fk++;
				else if(s[i]=='1') lu++;
				else fk++;
			}
			ans+=lu>=m;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<'\n';
		return 0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10) return sa::main();
	if(m==n){
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||!c[i])
				return cout<<"0\n",0;
		int fc=1;
		for(int i=1;i<=n;i++) fc=1ll*fc*i%MOD;
		return cout<<fc<<'\n',0;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			if(i-1-j<c[i])
				add(dp[i][j+1],dp[i-1][j]);
	for(int i=m;i<=n;i++) add(ans,dp[n][i]);
	cout<<ans<<'\n';
	return 0;
}

