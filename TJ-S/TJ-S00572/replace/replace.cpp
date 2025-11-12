#include<bits/stdc++.h>
#define int long long
using namespace std; 
map<string,int> m;
map<string,string> m1;
int q,n;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		m[a]=1;
		m1[a]=b;
	}
	while (q--)
	{
		int ans=0;
		string t1,t2,cmp1,cmp2,cmp3,cmp4;
		int start=1,end=1;
		cin>>t1>>t2;
		for (int i=0;i<t1.length();i++)
		{
			if (t1[i]!=t2[i])
			{
				start=i;
				break; 
			}
		}
		for (int i=0;i<t1.length();i++)
		{
			if (t1[i]!=t2[i])
			{
				end=i;
			}
		}
		for (int i=start;i<=end;i++)
		{
			cmp1+=t1[i];
			cmp2+=t2[i];
		}
		cmp3=cmp1;cmp4=cmp2;
		for (int i=start;i>=0;i--)
		{
			if (i!=start)
			{
				cmp1=t1[i]+cmp3;cmp2=t2[i]+cmp4;
				cmp3=cmp1;cmp4=cmp2;
			}
			for (int j=end;j<t1.length();j++)
			{
				if (j!=end) 
				{
					cmp1+=t1[j];
					cmp2+=t2[j];
				}
				if (m[cmp1]==1&&m1[cmp1]==cmp2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
