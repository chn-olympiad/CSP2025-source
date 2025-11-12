//李中易 SN-S00316 西安辅轮中学
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=200010;

int n,q,rot,tot,l[maxn],siz[maxn];
string s[maxn][5],t[5];
vector<int>num[maxn];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];siz[i]=s[i][1].size();
		s[i][1]="$"+s[i][1];s[i][2]="$"+s[i][2];
		l[i]=1;
		while(s[i][1][l[i]]==s[i][2][l[i]])  l[i]++;
	}
	while(q--)
	{
		cin>>t[1]>>t[2];
		int len=t[1].size();
		t[1]="$"+t[1];t[2]="$"+t[2];
		if(t[1].size()!=t[2].size())  { cout<<"0\n";continue; }
		int st=1,ed=len;
		while(t[1][st]==t[2][st])  st++;
		while(t[1][ed]==t[2][ed])  ed--;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int flag=1;
			for(int j=l[i],k=st;j>0;j--,k--)
			{
				if(k<=0)  { flag=0;break; }
				if(s[i][1][j]!=t[1][k]||s[i][2][j]!=t[2][k])  { flag=0;break; }
			}
			int k=st;
			for(int j=l[i];j<=siz[i];j++,k++)
			{
				if(k>len)  { flag=0;break; }
				if(s[i][1][j]!=t[1][k]||s[i][2][j]!=t[2][k])  { flag=0;break; }
			}
			k--;if(flag&&k>=ed)  ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
