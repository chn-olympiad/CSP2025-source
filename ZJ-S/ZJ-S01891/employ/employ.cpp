#include<bits/stdc++.h>
using namespace std;
const int N=20,M=262500,MOD=998244353;
int n,m;
int c[N];
vector<int> sta[20];
vector<int> emp[M];
void presolve(){
	for(int S=0;S<(1<<n);++S){
		int pos=0;
		for(int i=1;i<=n;++i){
			if(((S>>(i-1))&1)==0){
				emp[S].push_back(i);
			}else{
				pos++;
			}
		}
		sta[pos].push_back(S);
	}
}
char s[N];
int f[N][N][M];
int ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;i++) cin>>c[i];
	presolve();
	f[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i-1;j++){//i-1天拒绝的人为j 
			for(int S:sta[i-1]){//i-1天考虑的人的情况为S 
				for(int peo:emp[S]){//第i天可以安排的人为peo 
					int SS=S|(1<<(peo-1));
					if(j>=c[peo]||s[i]=='0'){
						f[i][j+1][SS]+=f[i-1][j][S];
						if(f[i][j+1][SS]>=MOD) f[i][j+1][SS]-=MOD;
					}else{
						f[i][j][SS]+=f[i-1][j][S];
						if(f[i][j][SS]>=MOD) f[i][j][SS]-=MOD;
					}
				}
			}
		}
	}
	int end=sta[n][0];
	for(int i=0;i<=n-m;i++){
		ans+=f[n][i][end];
		if(ans>=MOD) ans-=MOD;
	}
	cout<<ans;
	return 0;
}
