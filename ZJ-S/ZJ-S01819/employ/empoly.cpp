#include<bits/stdc++.h>
using namespace std;
const int N=550,mod=998244353;
int n,m,c[N],a[N],ans;
string s;
bool f=1;
int main()
{
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			f=0;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		a[i]=i;
	}
	if(f)
	{
		ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
	}
	else
	{
		do{
			int cnt0=0,cnt1=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt0>=c[a[i]] || s[i-1]=='0')
				{
					cnt0++;
					continue;
				}
				cnt1++;
			}
			if(cnt1>=m)
				ans++;
		}while(next_permutation(a+1,a+n+1));
	}
	cout<<ans;
	return 0;
}
