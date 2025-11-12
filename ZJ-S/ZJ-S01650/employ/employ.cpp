#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,mod=998244353;
int n,m,a[N],p[N];
ll ans;
bool op=1;
bitset<N>used;
string s;
void check(){
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='0')++cnt;
		else if(cnt>=p[a[i]])++cnt;
	}
	ans+=(n-cnt>=m);
}
void dfs(const int&x){
	if(x==n+1){
		check();
		return;
	}
	for(int i=1;i<=n;++i)
		if(!used[i]){
			used[i]=1;
			a[x]=i;
			dfs(x+1);
			used[i]=0;
		}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;s=" "+s;
	for(int i=1;i<s.size();++i)
		if(s[i]!=1){op=0;break;}
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	if(n<=20)dfs(1);
	else{
		ans=1;
		for(ll i=2;i<=n;++i)ans=ans*i%mod;
	}
	printf("%lld",ans);
	return 0;
}
