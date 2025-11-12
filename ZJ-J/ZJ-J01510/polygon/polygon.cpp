#include<bits/stdc++.h>
using namespace std;
int read()
{
	int val(0),f(1);
	char ch(getchar());
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		val*=10,val+=ch-'0';
		ch=getchar();
	}
	return val*f;
}
int n,a[5005],ans;
const int MOD=998244353;
bool flag=true;
int C(int a,int b)
{
	int ret=1,mx=(a>b-a?a:b-a),
mi=(a<b-a?a:b-a);
	for(int i=mx+1;i<=b;i++)
		ret*=i,ret%=MOD;
	for(int i=2;i<=mi;i++)
		ret/=i;
	return ret;
}
void dfs(int now,int val,int c)
{
	if(now>n) return;
	if(a[now]<val) ans++,ans%=MOD;
	dfs(now+1,val+a[now],c+1);
	dfs(now+1,val,c);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]!=1) flag=false;
	}
	if(flag)
	{
		for(int i=4;i<=n;i++)
			ans+=C(i,n)%MOD,ans%=MOD;
		printf("%d",ans);
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
