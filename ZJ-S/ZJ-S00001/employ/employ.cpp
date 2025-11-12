#include <bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
using namespace std;
const ll p=998244353;
const int N=505;
int n,m;
string s;
int c[N];

ll f[1<<18][20];
//int f[101][101][101];

ll ans;

int flag=1;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=0;i<n;i++) cin>>c[i];
	
//	for(int i=1;i<=n;i++) flag&=s[i]=='1';
//	if(flag){
//		ll res=1; for(int i=n;i>=1;i--) res=res*i%p; cout<<res; return 0;
//	}
	f[0][0]=1;
	for(int i=0;i<1<<n;i++){
		int tot=__builtin_popcount(i);
		for(int j=0;j<=n;j++){
//			cout<<i<<" "<<j<<" : "<<f[i][j]<<'\n';
			for(int k=0;k<n;k++){
				if(!(i>>k&1)){
					int i0=i|1<<k;
					if(tot-j>=c[k]||s[tot+1]=='0') f[i0][j]+=f[i][j],f[i0][j]%=p;
					else f[i0][j+1]+=f[i][j],f[i0][j]%=p;
				}
			}
			
		}
	}
	for(int i=m;i<=n;i++) ans=(ans+f[(1<<n)-1][i])%p;
	cout<<ans;
//	f[0][0][0]=1;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			for(int k=1;k<=j;k++){
//				for(int l=1;l<=n;l++){
//					if(s[i]=='0') f[i][j][k]=f[i-1][j][k-1];
//					else{
//						if(c[i]>=)
//					}
//				}
//			}
//		}
//	}
	
	return 0;
}