#include<bits/stdc++.h>
using namespace std;
string s[200100][2];
int n,q;
int a[200100][2][2];
void work(string q1,string q2)
{
	long long ans=0;
	for(int w=1;w<=n;w++)
	{
		int len1=q1.length(),len2=s[w][1].length();
		for(int i=0;i+len2-1<len1;i++)
		{
			string t=q1;
			for(int j=0;j<len2;j++)
			{
				//cout<<q1[i+j]<<" "<<s[w][0][j]<<w<<" "<<i+j<<" "<<i<<" "<<j<<'\n';
				if(q1[i+j]!=s[w][0][j])
				{
					//cout<<q1[i+j]<<" "<<s[w][0][j]<<w<<" "<<i+j<<" "<<i<<" "<<j<<'\n';
					break;
				}
				else
				{
					t[i+j]=s[w][1][j];
				}
			}
			if(t==q2)
			{
				//cout<<w<<'\n';
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	bool sub=1;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=1;j++)
		{
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=1;j++)
		{
			int cnt=0;
			for(int k=0;k<s[i][j].length();k++)
			{
				if(s[i][j][k]=='b')cnt++;
				if((s[i][j][k]!='a'&&s[i][j][k]!='b')||cnt>1)
				{
					//cout<<"XXX"<<'\n';
					sub=0;
					break;
				}
				if(!sub)break;
			}
		}
		if(!sub)break;
	}
	if(sub)
	{
		//cout<<"XXX";
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=1;j++)
			{
				int now=0;
				for(int k=0;k<s[i][j].length();k++)
				{
					if(s[i][j][k]=='b')now=1;
					a[i][j][now]++;
				}
			}
		}
		for(int i=1;i<=q;i++)
		{
			string s1,s2;
			cin>>s1>>s2;
			int f=0;
			int cnt1=0,cnt2=0;
			for(int j=0;j<s1.length();j++)
			{
				if(f&&s1[j]=='a')cnt2++;
				if(!f&&s1[j]=='a')cnt1++;
				if(s1[j]=='b')f=1;
			}
			f=0;
			int cnt3=0,cnt4=0;
			for(int j=0;j<s2.length();j++)
			{
				if(f&&s2[j]=='a')cnt3++;
				if(!f&&s2[j]=='a')cnt4++;
				if(s2[j]=='b')f=1;
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt1-a[i][0][0]+a[i][1][0]==cnt3&&cnt2-a[i][0][1]+a[i][1][1]==cnt4)ans++;
			}
			cout<<ans<<'\n';
		}
	}
	if(n>1e4)
	{
		for(int i=1;i<=q;i++)
		{
			cout<<0<<'\n';
		}
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		work(s1,s2);
	}
}
