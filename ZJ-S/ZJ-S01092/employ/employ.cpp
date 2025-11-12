#include<bits/stdc++.h>
#define IOS cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define ll long long
#define db double
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define pb push_back
#define eb emplace_back
#define PLL pair<ll,ll>
#define PII pair<int,int>
#define lb(x) ((x)&(-x))
using namespace std;
const int N=5e2+5,M=1e5+20;
const ll INF=1ll<<60,mod=998244353;
int n,m,c[N],sum[N],fan[N];
ll pre[N];
bool s[N];
void init(){
	pre[0]=1;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]*i%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	IOS;cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		char ch;cin>>ch;
		s[i]=ch-'0';
		sum[i]=sum[i-1]+(!s[i]);
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+1+n);
	if(sum[n]==n) cout<<pre[n]<<"\n",exit(0);
	if(n==m){
		cout<<0<<"\n";
		return 0;
	}
	if(m==1 && !sum[n]) cout<<0<<"\n",exit(0);
	if(n<=10){
		for(int i=1;i<=n;i++) fan[i]=i;
		int ans=0;
		do{
			int tp=0,Sum=0;
			for(int i=1;i<=n;i++){
				if(Sum<c[fan[i]] && s[i]) tp++;
				else Sum++;
			}
			ans+=tp>=m;
//			for(int i=1;i<=n;i++) cout<<fan[i]<<" ";cout<<"\n";
//			cout<<tp<<"\n";
		}while(next_permutation(fan+1,fan+1+n));
		cout<<ans<<"\n";
		return 0;
	}
	if(m==1){
		
		return 0;
	}
	return 0;
}

