#include<bits/stdc++.h>
#define popc(x) __builtin_popcount(x)
using namespace std;
const int M=505,N=18,mod=998244353;
inline void add(int &x,int v){ x=(x+v)%mod; }
int n,m,c[M],s[M],f[N+1][1<<N];
vector<int> sts[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	string str;
	cin>>str;
	for(int i=1;i<=n;i++) s[i]=str[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int s=0;s<(1<<n);s++){
		sts[popc(s)].push_back(s);
	}
	if(m==n){
		int ans=1;
		for(int i=1;i<=n;i++) ans&=(s[i]==1);
		for(int i=1;i<=n;i++) ans&=(c[i]>0);
		cout<<ans<<"\n";
		return 0;
	}
	if(m==1){
		int ans=1,tmp=1,p=0,p2=0;
		for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
		for(int i=1;i<=n;i++){
			if(s[i]==1){
				int cnt=0;
				for(int k=1;k<=n;k++) cnt+=(c[k]<i);
				tmp=1ll*tmp*(cnt-p)%mod;
				p++;
			}
			else{
				p2++,tmp=1ll*tmp*p2%mod;
			}
		}
		cout<<(ans-tmp+mod)%mod<<"\n";
		return 0;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int k=0;k<i;k++){
			for(int st:sts[i-1]){
				for(int j=1;j<=n;j++){
					if((st>>(j-1))&1) continue;
					int nk=k+(!s[i] || (k>=c[j])),nst=st|(1<<(j-1));
					add(f[nk][nst],f[k][st]);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++) add(ans,f[i][(1<<n)-1]);
	cout<<ans<<"\n";
}