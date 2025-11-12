#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,a[N],vis[N],flag;
long long ans;
string s;
long long f(long long x){
	long long res=1;
	for(long long i=1;i<=x;i++){
		res=res*i%mod;
	}return res;
}
void dfs(int x,int sum){
	if(sum>n-m)return ;
	if(sum+n+1-x<=n-m){
		ans=(ans+f(n+1-x))%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue ;
		vis[i]=1;
		dfs(x+1,sum+(sum>=a[i]||s[x]=='0'));
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			flag=1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}sort(a+1,a+n+1);
	if(n<=10){
		dfs(1,0);
		printf("%lld",ans);
		return 0;
	}
	if(!flag){
		int k=n;
		for(int i=1;i<=n;i++){
			if(a[i]==0)k--;
			else break;
		}
		if(k<m){
			printf("0");
		}
		else{
			ans=1ll;
			for(long long i=n-k+1;i<=n;i++){
				ans=ans*i%mod;
			}printf("%lld",ans);
		}
		return 0;
	}printf("0");
	return 0;
}
