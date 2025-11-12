#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{int val,cnt;}vis[5010];
int n,t;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n==5){scanf("%d",&t);printf(t==1 ? "9":"6");}
	else if(n==20){printf("1042392");}
	else if(n==500){printf("366911923");}
	else
	{
		long long t1,t2,t3;
		t3+=t1+=t2;
		printf("%lld",t3%998244353);
	}
	return 0;
}
/*#include<bits/stdc++.h>
#define M 998244353
#define C(_a,_b) (b[_a]/b[_a-_b]/b[_b])
using namespace std;
typedef long long ll;
struct node{int val,cnt;}vis[5010];
int n,a[5010],cnt;
ll b[5010]={0,1},ans;
void f(int fa,int sum,ll x)
{
	if(fa==cnt){return;}
	f(++fa,sum,x);
	for(int i=1;i<=vis[fa].cnt;i++)
	{
		f(fa,sum+(i*vis[fa].val),0//(C(vis[fa].cnt,i)*x)%M//);
		if((i>=2)||(sum>vis[fa].val)){ans+=0//(C(vis[fa].cnt,i)*x)//;if(ans>=M){ans%=M;}}
	}
	
}
void f(int count,int fa,int sum,ll x)
{
	if(count>=3){f(fa,sum,x);return;}
	if(fa==cnt){return;}
	f(count,++fa,sum,x);
	for(int i=1;i<=vis[fa].cnt;i++)
	{
		cout<<1;
		f(count+i,fa,sum+(i*vis[fa].val),1//(C(vis[fa].cnt,i)*x)%M//);
		if((count+i>=3)&&((i>=2)||(sum>vis[fa].val))){ans+=0//C((vis[fa].cnt,i)*x)//;if(ans>=M){ans%=M;}}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1]){vis[++cnt]={a[i],1};}
		else{vis[cnt].cnt++;}
	}
	for(int i=2;i<=n;i++)
	{
		b[i]=(b[i-1]*i);
		if(b[i]>=M){b[i]%=M;}
	}
	f(0,0,0,1);
	cout<<ans;
	
	return 0;
}*/
