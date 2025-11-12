#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=510;
const int mod=998244353;
int n,m,l,a[N],f[19][19][1<<18];
char s[N];
inline int read()
{
	char x=getchar();
	int ans=0;
	while(x<'0'||x>'9')
		x=getchar();
	while(x>='0'&&x<='9')
	{
		ans=(ans<<1)+(ans<<3)+(x^48);
		x=getchar();
	}
	return ans;
}
void add(int &x,int y)
{
	x+=y;
	x=(x>=mod?x-mod:(x<0?x+mod:x));
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(m==n)
	{
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||a[i]==0)
				flag=1;
		}
		if(flag==1)
			puts("0");
		else
		{
			int ans=1;
			for(int i=1;i<=n;i++)
				ans=(ll)ans*i%mod;
			printf("%d\n",ans);
		}
		return 0;
	}
	if(n<=18)
	{
		f[0][0][0]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				for(int S=0;S<(1<<n);S++)
				{
					if(!f[i][j][S])
						continue;
//					cout<<i<<" "<<j<<" "<<S<<" "<<f[i][j][S]<<endl;
					for(int k=1;k<=n;k++)
					{
						if(S&(1<<(k-1)))
							continue;
						int x=0;
						if(s[i+1]=='0'||j>=a[k])
							x=1;
						add(f[i+1][j+x][S|(1<<(k-1))],f[i][j][S]);
					}
				}
			}
		}
		int sum=0;
		for(int i=0;i<=n-m;i++)
			add(sum,f[n][i][(1<<n)-1]);
		printf("%d\n",sum);
		return 0;
	}
	puts("0");
}
