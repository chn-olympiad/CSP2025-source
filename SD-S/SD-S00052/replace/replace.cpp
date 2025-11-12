#include<bits/stdc++.h>
using namespace std;

const int N=2e5+101;
const int Q=5e6+101;

long long n,q;
string s1[N],s2[N];
string t1[Q],t2[Q];
long long len[N];

signed main()
{
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
	}
	for (int i=1;i<=q;i++)
	{
		
		int ans=0;
		cin>>t1[i]>>t2[i];
		t1[i]=' '+t1[i];
		t2[i]=' '+t2[i];
		int l=0,r=t1[i].size();
		for (int x=1;x<=t1[i].size()-1;x++)
		{
			if (t1[i][x]==t2[i][x]) l++;
			else break;
		}
		for (int x=t2[i].size()-1;x>=1;x--)
		{
			if (t1[i][x]==t2[i][x]) r--;
			else break;
		}
		for (int l1=0;l1<=l;l1++)
		{
			for (int r1=t1[i].size();r1>=r;r1--)
			{
				long long len2=r1-l1-1;
				for (int j=1;j<=n;j++)
				{
					if (len[j]==len2)
					{
						int num=1;
						for (int k=l1+1;k<=r1-1;k++)
						{
							if (s2[j][num]==t2[i][k]) num++;
						}
						num--;
						if (num==r1-l1-1) ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
