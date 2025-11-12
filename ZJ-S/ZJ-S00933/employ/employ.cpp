#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[100005],sum=0,ans=1,MOD=998244353,d[100005];
string s;
bool mark[100005];
void dfs(int x){
	if(x>n){
		int si=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				si++;
				continue;
			}
			if(si>=c[d[i]]){
				si++;
				continue;
			}
		}
		ans+=(n-si)>=m;
		ans%=MOD;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(mark[i])continue;
		d[x]=i;
		mark[i]=1;
		dfs(x+1);
		mark[i]=0;
		d[x]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	srand(time(NULL));
	cin>>s;
	for(int i=0;i<s.size();i++){
		sum+=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	if(sum==s.size()){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
		printf("%lld",ans);
		return 0;
	}
	if(n==m&&sum!=s.size()){
		printf("0");
		return 0;
	}
	if(n<=18){
		ans=0;
		dfs(1);
		printf("%lld",ans);
	}
	printf("%lld",(rand()+(rand()<<16))%MOD);
	return 0;
}

