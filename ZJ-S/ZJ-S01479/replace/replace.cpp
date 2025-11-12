#include<bits/stdc++.h>
using namespace std;
string s[100001][3];
int nxt[100001];
int ans[100001];
int gs;
void kmp(string a,string b)
{
	int n=b.size();
	b='@'+b;
	nxt[1]=0;
	int j=0;
	for(int i=2;i<=n;i++)
	{
		while(j!=0&&b[i]!=b[j+1])
		{
			j=nxt[j];
		}
		if(b[i]==b[j+1])
		{
			nxt[i]=nxt[j]+1;
			j++;
		}
	}
	int m=a.size();
	a='@'+a;
	j=0;
	for(int i=1;i<=m;i++)
	{
		while(j!=0&&a[i]!=b[j+1])
		{
			j=nxt[j];
		}
		if(a[i]==b[j+1])
		{
			j++;
		}
		if(j==n)
		{
			gs++;
			ans[gs]=i-n;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		string a,b;
		cin>>a>>b;
		int anss=0;
		for(int j=1;j<=n;j++)
		{
			gs=0;
			kmp(a,s[j][1]);
			for(int k=1;k<=gs;k++)
			{
				int ll=s[j][1].size();
				if(a.substr(0,ans[k])+s[j][2]+a.substr(ans[k]+ll,a.size()-(ans[k]-1)-ll)==b)
				{
					anss++;
				}
			}
		}
		cout<<anss<<endl;
	}
	return 0;
}
