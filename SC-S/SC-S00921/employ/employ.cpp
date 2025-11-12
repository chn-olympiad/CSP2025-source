#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=20,mod=998244353,M=3e5;
int s[N],c[N],n,m,f[M][N],ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char k;
		cin>>k;
		s[i]=k-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=20){
		f[0][0]=1;
		for(int i=0;i<(1<<n);i++){
			int tmp=i,cnt=0;
			while(tmp){
				int p=lowbit(tmp);
				int id=log2(p)+1;
				cnt++;
				tmp-=p;
			}
			if(cnt==n){
				for(int j=0;n-j>=m;j++) ans=(ans+f[i][j])%mod;
			}
			for(int j=0;j<=cnt;j++){
				int x=((1<<n)-1)^i;
				int tmp2=x;
				while(tmp2){
					int p=lowbit(tmp2);
					int id=log2(p)+1;
					if(s[cnt+1]==0) f[i|p][j+1]=(f[i|p][j+1]+f[i][j]);
					else{
						if(j>=c[id]) f[i|p][j+1]=(f[i|p][j+1]+f[i][j]);
						else f[i|p][j]=(f[i|p][j]+f[i][j]);
					}
					tmp2-=p;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
