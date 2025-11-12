#include<cstdio>
#include<algorithm>
typedef long long ll;
const ll N=1e6+5,MOD=998244353;
ll n,m;
char s[N];
ll c[N];
ll ans=0;
void dfs(ll x=n){
	if(!x){
		ll cnt=0,gu=0;
		for(ll i=1;i<=n;++i){
			if(s[i]=='0') ++gu;
			else if(gu>=c[i]) ++gu;
			else ++cnt;
		}if(cnt>=m) ++ans;
		return ;
	}for(ll i=1;i<=x;++i){
		std::swap(c[i],c[x]);
		dfs(x-1);
		std::swap(c[i],c[x]);
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	scanf("%s", s+1);
	for(ll i=1;i<=n;++i){
		scanf("%lld", &c[i]);
	}
	if(n<=10){ // 搜索 
		dfs();
		printf("%lld\n", ans);
	}else{
		bool flag=true;
		for(ll i=1;i<=n;++i){
			if(!c[i]||s[i]=='0'){
				flag=false;
				break;
			}
		}if(!flag){
			puts("0");
		}else{
			ans=1;
			for(ll i=1;i<=n;++i){
				(ans*=i)%=MOD;
			}printf("%lld\n", ans);
		}
	}
	return 0;
}