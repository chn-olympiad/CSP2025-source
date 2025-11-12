#include<bits/stdc++.h>
using namespace std;
int n,q,ls[2][2000005],lt[2][2000005],
zuol[2000005],youl[2000005],chal[2000005],
zuot[2000005],yout[2000005],chat[2000005];
string s[2][2000005],t[2][2000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[0][i];ls[0][i]=s[0][i].length();
		cin>>s[1][i];ls[1][i]=s[1][i].length();
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[0][i];lt[0][i]=t[0][i].length();
		cin>>t[i][i];lt[1][i]=t[1][i].length();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<ls[0][i];j++)
		{
			if(s[0][i][j]=='b')
			{
				zuol[i]=j;
				youl[i]=ls[0][i]-zuol[i]-1;
				chal[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<ls[1][i];j++)
		{
			if(s[1][i][j]=='b')
			{
				chal[i]-=j;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=0;j<lt[0][i];j++)
		{
			if(t[0][i][j]=='b')
			{
				zuot[i]=j;
				yout[i]=lt[0][i]-zuot[i]-1;
				chat[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=0;j<lt[1][i];j++)
		{
			if(t[1][i][j]=='b')
			{
				chat[i]-=j;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(lt[0][i]!=lt[1][i])
		{
			cout<<"0\n";
			continue;
		}
		long long ans=0;
		for(int j=1;j<=n;j++)
		{
			if(chat[i]==chal[j]&&zuot[i]>=zuol[j]&&yout[i]>=youl[j])
				ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
