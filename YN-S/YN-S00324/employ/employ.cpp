#include <iostream>
using namespace std;
const int N=600,T=998244353;
int n,m;
long long ans;
string a;
int b[N];
int us[N];

int read()
{
	int num=0,f=1;
	char a=getchar();
	while(a<'0'||a>'9')
	{
		if(a=='-') f=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9')
	{
		num=num*10+a-'0';
		a=getchar();
	}
	return num;
}

long long ops(int x)
{
	long long res=1;
	for(int i=2;i<=x;i++)
		res=(res*i)%T;
	return res;
}

void dfs(int cnt,int em,int unem)
{
	if(em>=m) 
	{
		ans+=ops(n-cnt+1);
		ans%=T;
		return ;
	}
	if(cnt>n) return ;
	
	for(int i=1;i<=n;i++)
	{
		if(!us[i])
		{
			if(a[cnt-1]-'0'&&unem<b[cnt])
			{
				us[i]=1;
				dfs(cnt+1,em+1,unem);
				us[i]=0;
			}
			else
			{
				us[i]=1;
				dfs(cnt+1,em,unem+1);
				us[i]=0;
			}
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	cin>>a;
	for(int i=1;i<=n;i++)
		b[i]=read();
	dfs(1,0,0);
	cout<<ans%T;
	return 0;
}
