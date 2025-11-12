#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],num1,num0,ans=0;
string s;
int bj[N];
void dfs(int dep,int leave){
	if(dep==n+1)
	{
		if(n-leave>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(bj[i]) continue;
		bj[i]=1;
		if(leave>=c[i]) dfs(dep+1,leave+1);
		else if(s[dep-1]=='0') dfs(dep+1,leave+1);
		else dfs(dep+1,leave);
		bj[i]=0;
	}
}
signed main(){//不晓得啥时候写出来的暴搜 预估10分 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0) num0++;
	}
	int len=s.size();
	for(int i=0;i<len;i++) num1+=s[i]-'0';
	if(num1==n){
		for(int i=1;i<=n-num0;i++){
			ans*=i;
			ans%=mod;
		}
		printf("%lld",ans);
	}else{
		dfs(1,0);
		printf("%lld",ans);
	}
	return 0;
}
