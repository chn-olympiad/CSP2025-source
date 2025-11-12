#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define dd double
using namespace std;

int n,q;
string s,t;
int a[N][5];
ll ans=0;

int l=0;
int ls=0,lt=0;
int e=0,e_=0,r=0,r_=0;

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;++i)
	{
		cin >> s >> t;
		l=s.size();
		for(int j=0;j<l;++j)
		{
			if(s[j]=='b')
			{
				a[i][1]=j;
				a[i][2]=l-j-1;
				break;
			}
		}
		for(int j=0;j<l;++j)
		{
			if(t[j]=='b')
			{
				a[i][3]=j;
				a[i][4]=l-j-1;
				break;
			}
		}
	}
	while(q--)
	{
		ans=0;
		cin >> s >> t;
		ls=s.size();
		lt=t.size();
		for(int i=0;i<ls;++i)
		{
			if(s[i]=='b') 
			{
				e=i;
				r=ls-e-1;
				break;
			} 
		}
		for(int i=0;i<lt;++i)
		{
			if(t[i]=='b') 
			{
				e_=i;
				r_=lt-e_-1; 
				break;
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(a[i][1]<=e && a[i][2]<=r && a[i][3]-a[i][1]+e==e_) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}

