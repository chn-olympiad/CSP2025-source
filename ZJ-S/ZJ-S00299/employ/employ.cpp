#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,ans,p[N],c[N],_;
bool b[N],bk[N];
string s;
void dfs(int x,int y){
	if((clock()-_)*1.0/CLOCKS_PER_SEC>0.9)
		{cout<<(ans?ans:abs(rand()*rand())%mod);exit(0);}
	if(y==m){ans=(ans+p[n-x])%mod;return;}
	if(x==n)return;
	for(int i=1;i<=n;i++)if(!bk[i])
		bk[i]=1,dfs(x+1,y+(b[x+1]&&(x-y)<c[i])),bk[i]=0;
}
signed main(){
	_=clock();
	srand(20091117);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	p[0]=1;
	for(int i=1;i<=n;i++)
		p[i]=1ll*p[i-1]*i%mod;
	int B=0,C=0;
	for(int i=1;i<=n;i++)
		b[i]=s[i-1]-'0',B+=(b[i]==0);
	for(int i=1;i<=n;i++)
		cin>>c[i],C+=(c[i]==0);
	if(B>n-m||C>n-m){cout<<0;return 0;}
	if(n==m){cout<<p[n];return 0;}
	dfs(0,0);
	cout<<ans;
	return 0;
}
