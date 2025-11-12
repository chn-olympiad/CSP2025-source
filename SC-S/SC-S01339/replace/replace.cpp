#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=200020;
string s1[N],s2[N],s,t;
int siz[N];
int st,ed;
int main()
{
//	system("fc replace.out replace3.ans");return 0;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	if(n>100000)
	{
		while(q--)
		{
			cout<<0<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		siz[i]=s1[i].size();
	}
	while(q--)
	{
		cin>>s>>t;
		int sizs=s.size();
		st=ed=0;
		st--;
		int ans=0;
		for(int i=sizs-1;i>=0;i--)
		{
			if(s[i]!=t[i])
			{
				ed=i;
				break;
			}
		}
		for(int i=0;i<sizs;i++)
		{
			if(s[i]!=t[i])
			{
				st=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(st!=-1&&siz[i]<(ed-st+1))
			{
				continue;
			}
			if(siz[i]>sizs)
			{
				continue;
			}
			for(int j=0;j<(sizs-siz[i]+1);j++)
			{
				if(st!=-1&&j>st)
				{
					break;
				}
				if(j+siz[i]-1<ed)
				{
					continue;
				}
				for(int k=0;k<siz[i];k++)
				{
					if(s[j+k]!=s1[i][k])
					{
						goto fal;
					}
				}
				for(int k=0;k<siz[i];k++)
				{
					if(t[j+k]!=s2[i][k])
					{
						goto fal;
					}
				}
				ans++;
				fal:;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}