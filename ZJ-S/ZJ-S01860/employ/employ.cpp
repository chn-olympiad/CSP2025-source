#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,a[N],f[15],anss;
bool vis[15];
string s;
void dfs(int u){
	if(u==n+1){
		int cnt=0,res=0;
		for(int i=1;i<=n;i++){
			if(cnt>=a[f[i]]||s[i-1]=='0') cnt++;
			else res++;
		}
		if(res>=m) anss++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		f[u]=i;
		dfs(u+1);
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<=18){
		dfs(1);
		printf("%d",anss);
	}
	else if(m==1){
		sort(a+1,a+1+n);
		long long ans=1,res=1;
		for(int i=2;i<=n;i++)
			ans=(ans*i)%mod;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				cnt++;
				continue;
			}
			int k=upper_bound(a+1,a+1+n,i)-a-1;
			if(k-i+1<=0){
				printf("%lld",ans);
				return 0;
			}
			res=(res*(k-i+1))%mod;
		}
		for(int i=1;i<=cnt;i++)
			res=(res*i)%mod;
		printf("%lld",(ans-res+mod)%mod);
	}
	else{
		long long ans=1;
		for(int i=2;i<=n;i++)
			ans=(ans*i)%mod;
		printf("%lld",ans);
	}
	return 0;
}
