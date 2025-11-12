#include<iostream>
using namespace std;
const long long mod=998244353;
int n,m,c[500],p[500];
char s[500];
bool b,vis[500];
long long ans;
void dfs(int x,int cnt){
	if(cnt>n-m)return;
	if(x!=n){
		for(int i=0;i<n;i++){
			if(!vis[i]){
				vis[i]=1,p[x]=i;
				dfs(x+1,cnt+((cnt>=c[i])|(s[x]!='1')));
				vis[i]=0;
			}
		}
	}else ans=(ans+1)%mod;
}int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	b=1;
	scanf("%d%d",&n,&m),scanf("%s",s);
	for(int i=0;i<n;i++)scanf("%d",&c[i]),b&=c[i];
	for(int i=0;i<n;i++)b&=(s[i]-'0');
	if(!(m^n)){
		if(b){
			ans=1;
			for(int i=1;i<=n;i++)ans=(ans*i)%mod;
			printf("%lld",ans);
		}else putchar('0');
		return 0;
	}dfs(0,0),printf("%lld",ans);
	return 0;
}
