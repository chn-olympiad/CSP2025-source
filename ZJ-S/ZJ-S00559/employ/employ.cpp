#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long
#define N 509
ll m,n,ans,a[N],fg1=1,fg2=1;
char s[N];
ll A(ll x)
{
	ll ret=1;
	for(ll i=1;i<=x;i++) ret=ret*i,ret%=MOD; 
	return ret%MOD;
}
void sub1()
{
	//printf("MEG");
	for(int i=1;i<=n;i++) if(a[i]==0) n--;
	ans=A(n);
	printf("%lld\n",ans);
}
void sub2()
{
	//printf("OP");
	ll st=-1,tmp=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1'){st=i-1;break;}
	}
	if(st==-1){printf("0\n");return;}
	for(int i=1;i<=n;i++) tmp+=(a[i]>st);
	printf("%lld %lld\n",tmp,st);
	ans=tmp*A(n-1)%MOD;
	printf("%lld\n",ans);
}
ll flag[20],cnt[20];
bool check()
{
	//for(int i=1;i<=n;i++) printf("%lld ",cnt[i]);
	ll cot=0,rf=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0') rf++;
		else if(rf>=a[cnt[i]]) rf++;
		else cot++; 
		//printf("%lld ",cot);
	}
	//printf("cnt %lld\n",cot);
	return (cot>=m);
}
ll dfs(int u)
{
	//printf("%d\n",u);
	if(u>n) return check();
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		if(flag[i]) continue;
		flag[i]=1,cnt[u]=i;
		sum+=dfs(u+1);
		flag[i]=0;
	}
	return sum;
}
void sub3()
{
	//printf("ME");
	memset(flag,0,sizeof(flag));
	printf("%lld\n",dfs(1)%MOD);
}
void sub4()
{
	if(fg1==1&&fg2==1) printf("%lld\n",A(n));
	else printf("0\n");
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),fg1=min(fg1,1ll*s[i]-'0'),fg2=min(fg2,a[i]);
	if(m==n) sub4();
	else if(fg1==1) sub1();
	else if(m==1) sub2();
	else if(n<=18) sub3();
	else printf("0\n");
	return 0;
}