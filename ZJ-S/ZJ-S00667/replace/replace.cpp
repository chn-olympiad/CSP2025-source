#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+3,M=2e3+3,base=131,mod=1e9+7;
int n,q,c[M][M],d[M][M],l[N];
bool f[M],b[M];
int a1[N],a2[N];
char s1[M],s2[M],t1[M],t2[M];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>(s1+1)>>(s2+1);
		l[i]=strlen(s1+1);
		for (int j=1;j<=l[i];j++){
			a1[i]=(a1[i]*base+s1[j])%mod;
			a2[i]=(a2[i]*base+s2[j])%mod;
		}
	}
	while (q--){
		cin>>(t1+1)>>(t2+1);
		int res=0;
		int len=strlen(t1+1);
		f[0]=1;
		for (int i=1;i<=len;i++){
			f[i]=(f[i-1]&&(t1[i]==t2[i]));			
		}
		b[len+1]=1;
		for (int i=len;i>=1;i--){
			b[i]=(b[i+1]&&(t1[i]==t2[i]));
		}
//		for (int i=1;i<=len;i++) cout<<f[i]<<" "; cout<<"\n";
//		for (int i=1;i<=len;i++) cout<<b[i]<<" "; cout<<"\n";
		for (int i=1;i<=len;i++){
			for (int j=i;j<=len;j++){
				c[i][j]=(c[i][j-1]*base+t1[j])%mod;
				d[i][j]=(d[i][j-1]*base+t2[j])%mod;
			}
		}
		for (int i=1;i<=n;i++){
			for (int L=1;L<=len-l[i]+1;L++){
				int R=L+l[i]-1;
				if (f[L-1] && b[R+1] && c[L][R]==a1[i] && d[L][R]==a2[i]) res++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}

