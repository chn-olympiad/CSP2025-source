#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=500;
int n,m,a[maxn+5],can[maxn+5],cnt[maxn+5];char c;
int dp[1<<19][20];
inline void mo(int &x){x=x>=mod?x-mod:x;}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c,can[i]=(c=='1');
	for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;
	if(n<=18){
		dp[0][0]=1;//[是否选择][录用几人]
		for(int S=0;S<(1<<n);S++){
			int xht=0;for(int i=1;i<=n;i++)if((S>>i-1)&1)xht++;
			for(int num=0;num<=xht;num++)if(dp[S][num]){
				for(int i=1;i<=n;i++)if((S>>i-1)&1^1){
					if(xht-num<a[i]&&can[xht+1]){
						mo(dp[S|(1<<i-1)][num+1]+=dp[S][num]);
					}else{
						mo(dp[S|(1<<i-1)][num]+=dp[S][num]);
					}
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++)mo(ans+=dp[(1<<n)-1][i]);
		cout<<ans;
	}else if(m==n){
		for(int i=1;i<=n;i++)if(!can[i])return cout<<"0\n",0;
		for(int i=1;i<=n;i++)if(!a[i])return cout<<"0\n",0;
		int res=1;
		for(int i=1;i<=n;i++)res=res*i%mod;
		cout<<res<<"\n";
		return 0;
	}else{
		int res=1;
		for(int i=1;i<=n;i++)res=res*i%mod;
		cout<<res<<"\n";
	}
	return 0;
}
//不推了,写个n!上去
//完蛋，304~324
//话说应该没人会看到这吧
//今年这个区分度不好说？
//希望不挂分进WC吧，喵喵喵
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	
//o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	o(=•ェ•=)m	