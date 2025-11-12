#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,MOD=998244353;
int n,m;
char s[N];
int c[N];
namespace Solve1_2{
	const int N=18;
	int f[1<<N][N+1];// 用了哪些，走了几个
	vector<int> vec[N+1];
	void main(){
		for (int i=0;i<(1<<n);i++)
			vec[__builtin_popcount(i)].push_back(i);
		f[0][0]=1;
		for (int i=1;i<=n;i++){
			if (s[i]=='1'){
				for (const int &ste:vec[i]){
					for (int j=0;j<n;j++){
						if ((ste>>j)&1){
							for (int x=0;x<min(i+1,c[j+1]);x++)
								(f[ste][x]+=f[ste^(1<<j)][x])%=MOD;
							for (int x=c[j+1];x<i;x++)
								(f[ste][x+1]+=f[ste^(1<<j)][x])%=MOD;
						}
					}
				}
			}
			else{
				for (const int &ste:vec[i]){
					for (int j=0;j<n;j++){
						if ((ste>>j)&1){
							for (int x=1;x<=i;x++)
								(f[ste][x]+=f[ste^(1<<j)][x-1])%=MOD;
						}
					}
				}				
			}
		}
		int res=0;
		for (int i=m;i<=n;i++)
			(res+=f[(1<<n)-1][n-i])%=MOD;
		cout<<res<<"\n";
	}
}
signed main(){
#ifndef DEBUG
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#endif
//	freopen("employ\\employ3.in","r",stdin);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>s[i];
	for (int i=1;i<=n;i++)
		cin>>c[i];
	if (n<=18){
		Solve1_2::main();
		return 0;
	}
}
/*
555 我不要做恐怖大计数
*/