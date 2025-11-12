#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<48){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>47) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

const int N=520;
const int mod=998244353;
int n,m,a[N],s[N],dp[N][N],vis[N],p[N],ans;
int fl=0;
char ss[N];

inline void dfs(int pos){
	if(pos==n){
		int cnt=0;int sum=0;
		for(int i=1;i<=n;i++){
			if(cnt>=a[p[i]]){
				cnt++;
			}
			else{
				if(s[i]==0){
					cnt++;
				}
				else{
					sum++;
				}
			}
		}
		if(sum>=m){
			ans++;ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[pos+1]=i;
			dfs(pos+1);
			vis[i]=0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	int cnt=0;
	scanf("%s",ss+1);
	for(int i=1;i<=n;i++){
		s[i]=ss[i]-'0';
		if(s[i]==1){
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(cnt<m){
		printf("0\n");
	}
	else{
		dfs(0);
		printf("%lld",ans);
	}
	return 0;
} 
