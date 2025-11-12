#include<bits/stdc++.h>
using namespace std;
string s[200010][2],t[2];
int h[200010],e[200010],d[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		int l=s[i][0].length(),p0,p1;
		for(int j=0;j<l;j++)
			if(s[i][0][j]=='b'){p0=j;break;}
		for(int j=0;j<l;j++)
			if(s[i][1][j]=='b'){p1=j;break;}
		h[i]=p0,e[i]=l-p1,d[i]=p0-p1;
	}
	while(m--)
	{
		cin>>t[0]>>t[1];
		int l=t[0].length(),p0,p1,ans=0;
		for(int j=0;j<l;j++)
			if(t[0][j]=='b'){p0=j;break;}
		for(int j=0;j<l;j++)
			if(t[1][j]=='b'){p1=j;break;}
		for(int i=1;i<=n;i++)
			if(d[i]==p0-p1&&p0>=h[i]&&l-p1>=e[i])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
