#include<iostream>
#include<algorithm>
using namespace std;
constexpr int MOD=998244353;
string asr;
int n,m,a[510],w[510],f[300000][20],d;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>asr;
	for(int i=1;i<=n;i++)
		a[i]=asr[i-1]-'0';
	for(int i=1;i<=n;i++)
		cin>>w[i];
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int iz=__builtin_popcount(i);
		for(int j2=0;j2<n;j2++){
			if(i&1<<j2)
				continue;
			for(int j1=0;j1<=iz;j1++){
				if(a[iz+1] && w[j2+1]>iz-j1)
					f[i|1<<j2][j1+1]=(f[i|1<<j2][j1+1]+f[i][j1])%MOD;
				else
					f[i|1<<j2][j1]=(f[i|1<<j2][j1]+f[i][j1])%MOD;
			}
		}
	}
	for(int i=m;i<=n;i++)
		d=(d+f[(1<<n)-1][i])%MOD;
	cout<<d;
	return 0;
}
