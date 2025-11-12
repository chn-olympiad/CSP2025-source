#include <bits/stdc++.h>
#define N 2010
#define ull unsigned long long
#define bs 131
using namespace std;
int n,q;
string s[2][N],t[2][N];
bool f=1;
int ct;
int ans[N];
vector<ull> hsht[N];ull hshs[2][N],hsh[N];
ull qp[2010];
inline void chk2()
{
	for(int i=1;i<=q;i++)
	{
		hsht[i].push_back(0);
		for(int j=1;j<t[0][i].length();j++) hsht[i].push_back(hsht[i].back()*bs+t[0][i][j]);
		for(int j=1;j<t[1][i].length();j++) hsh[i]=hsh[i]*bs+t[1][i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<s[0][i].length();j++) hshs[0][i]=hshs[0][i]*bs+s[0][i][j];
		for(int j=1;j<s[1][i].length();j++) hshs[1][i]=hshs[1][i]*bs+s[1][i][j];
	}
	for(int i=1;i<=q;i++)
	{
		int res=0;
		for(int j=1;j<t[0][i].length();j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j+s[0][k].length()-2>=t[0][i].length()) continue;
				int l=j,r=j+s[0][k].length()-2;
				if(hsht[i][r]-hsht[i][l-1]*qp[s[0][k].length()-1]==hshs[0][k])
				{
					if(hsht[i].back()-(hshs[0][k]-hshs[1][k])*qp[t[0][i].length()-1-r]==hsh[i]) res++;
				}
			}
		}
		cout<<res<<'\n';
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	qp[0]=1;
	for(int i=1;i<=2005;i++) qp[i]=qp[i-1]*bs;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[0][i]>>s[1][i];
		s[0][i]=" "+s[0][i],s[1][i]=" "+s[1][i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[0][i]>>t[1][i];
		t[0][i]=" "+t[0][i],t[1][i]=" "+t[1][i];
	}
	chk2();
	return 0;
}
