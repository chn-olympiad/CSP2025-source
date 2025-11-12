#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int N=510;
const ll mod=998244353;
int p[100],n,m,c[N],sum[N];
char s[N];
bool flag[100];
ll ans;
bool check(){
	int cnt=0,tot=0;
	for(int i=1;i<=n;i++){
		if(tot>=c[p[i]]){
			tot++;
			continue;
		}
		if(s[i]=='0'){
			tot++;
			continue;
		}
		cnt++;
	}
	return cnt>=m;
}
void dfs(int x){
	if(x==n+1){
		if(check()){
			ans++;
			ans%=mod;
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(flag[i])continue;
		flag[i]=1;
		p[x]=i;
		dfs(x+1);
		flag[i]=p[x]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+s[i]-'0';
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	if(sum[n]<m){
		printf("0");
		return 0;
	}
	if(n<=20){
		dfs(1);
		printf("%d",ans);
		return 0;
	}
	else {
		ans=1;
		int num=n;
		for(int i=1;i<=n;i++)if(c[i]==0)num--;
		if(num<m){
			printf("0");
			return 0;
		}
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}

