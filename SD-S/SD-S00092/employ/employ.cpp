#include<bits/stdc++.h>
#define int long long
using namespace std;
bool st;
const int N=20;
const int mod=998244353;
char s[N];
int c[N];
int f[1<<N][N];//第二维是拒了多少个 
bool ed;
signed main(){
//	cerr<<(&st-&ed)/(1024.0*1024.0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		for(int k=0;k<n;k++){
			if(f[i][k]==0){
				continue;
			}
			int cnt=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					cnt++;//第几套试卷 
				}
			}
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					continue;
				}
				int now=(i|(1<<j));
				if(k>=c[j+1]){
					f[now][k+1]+=f[i][k];
					f[now][k+1]%=mod;
					continue;
				}
				if(s[cnt+1]=='0'){
					f[now][k+1]+=f[i][k];
					f[now][k+1]%=mod;
				}
				else{
					f[now][k]+=f[i][k];
					f[now][k]%=mod;
				}
//				cout<<i<<' '<<j<<' '<<now<<' '<<k<<' '<<f[i][k]<<"***\n";
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++){
//		cout<<i<<' '<<f[(1<<n)-1][i]<<"***\n";
		ans=(ans+f[(1<<n)-1][i])%mod;
	}
	cout<<ans;
	return 0;
}

