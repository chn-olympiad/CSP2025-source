#include<bits/stdc++.h>
#define int long long
using namespace std;
int p[2][5000005],n,q,ans,ccy[1000005],cy[1000005],cy2[1000005],Cy;
string s1[1000005],s2[1000005],t1,t2;
void kmp(string s,int x)
{
	int n=s.length();
	for (int i=1;i<s.length();i++)
	{
		int j=p[x][i-1];
		while (j&&s[i]!=s[j])
		{
			j=p[x][j-1];
		}
		if (s[i]==s[j])
		{
			j++;
		}
		p[x][i]=j;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		for (int j=0;j<s1[i].length();j++)
		{
			if (s1[i][j]!=s2[i][j])
			{
				ccy[i]++;
			}
		}
//		cout<<ccy[i]<<' ';
	}
//	kmp("aba ababababa",0);
//	for (int i=0;i<=10;i++)
//	{
//		cerr<<p[0][i]<<' ';
//	}
//	cerr<<'\n';
	while (q--)
	{
		cin>>t1>>t2;
		ans=Cy=0;
//		memset(p,0,sizeof(p));
		for (int i=0;i<t1.length();i++)
		{
			if (t1[i]!=t2[i])
			{
				Cy++;
				cy[i]=cy[i-1]+1;
			}
			else
			{
				cy[i]=cy[i-1];
			}
		}
		cy2[t1.length()]=1;
		for (int i=t1.length()-1;i>=0;i--)
		{
			if (t1[i]!=t2[i])
			{
				cy2[i]=cy2[i+1]+1;
			}
			else
			{
				cy2[i]=cy2[i+1];
			}
		}
//		cout<<Cy<<'|';
//		if (q==27578-102)
		for (int i=1;i<=n;i++)
		{
//			cerr<<i<<' ';
//			if (q!=27578-101)
//				break;
			if (Cy>ccy[i])
				continue;
			kmp(s1[i]+" "+t1,0);
			kmp(s2[i]+" "+t2,1);
			for (int j=s1[i].length()+1;j<s1[i].length()+t1.length()+1;j++)
			{
				if (p[0][j]==p[1][j]&&p[0][j]==s1[i].length())
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

