#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,mod=998244353;
int n,m,s[N],c[N];
long long ans;
int qread(){
	int ret=0;
	char c;
	do{
		c=getchar();
	}while(!isdigit(c));
	do{
		ret=ret*10+c-'0';
		c=getchar();
	}while(isdigit(c));
	return ret;
}
int per[N];
bool vis[N];
void dfs(int i,int num){
	per[i]=num;
	if(i==n){
		bool flag=0;
		int pas=0,ls=0;
		for(int j=1;j<=n;j++){
			if(ls>=c[per[j]]||s[j]==0){
				ls++;
				continue;
			}
			pas++;
			if(pas>=m){
				flag=1;
				break;
			}
		}
		if(flag)ans=(ans+1)%mod;
		return;
	}
	vis[num]=1;
	for(int j=1;j<=n;j++){
		if(!vis[j])dfs(i+1,j);
	}
	vis[num]=0;
}
void solve1(){
	dfs(0,0);
	printf("%lld",ans);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=qread();m=qread();
	char str[N];scanf("%s",str);
	int l=strlen(str);
	bool flag=1;
	for(int i=0;i<l;i++)s[i+1]=str[i]-'0',flag&=s[i+1];
	int cnt=0;
	for(int i=1;i<=n;i++){
		c[i]=qread();
		if(c[i]==0)cnt++;
	}
	if(flag){
		if(m+cnt>n)printf("0");
		else{
			long long ans=1;
			for(int i=n;i>=1;i--)ans=(ans*i)%mod;
			printf("%lld",ans);
		}
	}else if(n<=10)solve1();
	return 0;
}