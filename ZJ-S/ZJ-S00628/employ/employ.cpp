#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=510,M=998244353;
int n,m,ans,s[N],_,c[N],dp[20][1<<18],g[20][1<<18],sc[N];
string a;
vector<int> e[1<<18],le[18];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++)
		cin>>c[i],
		_|=a[i-1]=='0';
	for(int i=0;i<(1<<n);i++){
		int s=0;
		for(int j=0;j<n;j++)
			if(!(i>>j&1))
				e[i].push_back(j),
				s++;
		le[n-s].push_back(i);
	}
	if(n<=18){
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(auto j:le[i-1])
				for(int k=0;k<n;k++)
					g[k][j]=dp[k][j]%M,
					dp[k][j]=0;
			if(a[i-1]=='0'){
				for(auto j:le[i-1])
					for(int l=min(i,n-m);l;l--)
						if(g[l-1][j])
							for(auto k:e[j])
								dp[l][j+(1<<k)]+=g[l-1][j];
			}else
				for(auto j:le[i-1])
					for(int l=0;l<min(i,n-m+1);l++)
						if(g[l][j])
							for(auto k:e[j])
								if(c[k+1]<=l)
									dp[l+1][j+(1<<k)]+=g[l][j];
								else
									dp[l][j+(1<<k)]+=g[l][j];
		}
		for(int i=0;i<=n-m;i++)
			ans+=dp[i][(1<<n)-1]%M;
		cout<<ans%M;
		return 0;
	}
	if(!_){
		int g=0;
		s[0]=1;
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]*i%M,
			sc[c[i]]++;
		for(int i=1;i<=n;i++)
			sc[i]+=sc[i-1];
		for(int i=0,p=1;i<n;i++)
			(p*=sc[i]-i)%=M,
			g+=i+1>=n-m?p*s[n-i-1]%M:0;
		cout<<(s[n]-g%M+M)%M;
		return 0;
	}
	return 0;
}

