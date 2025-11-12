#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int T,a[3][N],n,ans,_1,_2;
inline int cinn()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*f;
}
void dfs(int noww,int a1,int a2,int a3,int aa)
{
	if(a1>n/2 || a2>n/2 || a3>n/2)
		return ;
	if(noww==n)
	{
		ans=max(aa,ans);
	}
	dfs(noww+1,a1+1,a2,a3,aa+a[0][noww]);
	dfs(noww+1,a1,a2+1,a3,aa+a[1][noww]);
	dfs(noww+1,a1,a2,a3+1,aa+a[2][noww]);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=cinn();
	while(T--)
	{
		_1=0;
		_2=0;
		n=cinn();
		for(int i=0;i<n;i++)
		{
			a[0][i]=cinn();
			a[1][i]=cinn();
			if(a[1][i]==0)
				_1++;
			a[2][i]=cinn();
			if(a[2][i]==0)
				_2++;
		}
		if(n<=10)
		{
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}
		else if(_1==n && _2==n)
		{
			sort(a[0],a[0]+n,greater<int>());
			for(int i=0;i<n/2;i++)
			{
				ans+=a[0][i];
			}
			cout<<ans<<endl;
		}
		else
		{
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}
		ans=0;
	}
	return 0;
}
