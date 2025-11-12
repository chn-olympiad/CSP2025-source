#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[502];
int a[502];
const int mod=998244353;
long long ans=0,ans2=0;
int num[502];
bool flag[502];
int sum[502];
void dfs(int now){
	if(now>n){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||cnt>=a[num[i]])
				cnt++;
		if(n-cnt>=m)	ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i])	continue;
		num[now]=i;
		flag[i]=true;
		dfs(now+1);
		flag[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	int cnta=0,cntb=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)	cntb++;
		if(s[i]==0)	cnta++;
	}
	if(cnta==0||cntb==0){
		printf("0\n");
		return 0;
	}
	if(n<=11){
		dfs(1);
		printf("%lld\n",ans);
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++)
			if(a[i]==0){
				printf("0\n");
				return 0;
			}
		for(int i=1;i<=n;i++)
			if(s[i]=='0'){
				printf("0\n");
				return 0;
			}
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		printf("%lld",ans);
		return 0;
	}
	printf("0\n");
	return 0;
}


