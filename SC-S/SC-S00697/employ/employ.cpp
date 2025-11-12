#include <bits/stdc++.h>
using namespace std;

const int N=501,M=998244353;
int n,m,c[N],ans[N],a,p,f,l=1,rt=1;
string s;
int pl(int n,int m)
{
	int ans=1;
	for(int i=n;i>n-m;i--)ans*=i;
	return ans;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	s='1'+s;
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			p++;
		}
		else
		{
			f++;
			int sum=0;
			for(;c[l]<=f;sum++,l++);
			ans[++a]=pl(sum,p);
			p=0;
		}
	}
	for(int i=1;i<=a;i++)
	{
		rt*=ans[i];
	}
	cout<<rt;
	return 0;
}