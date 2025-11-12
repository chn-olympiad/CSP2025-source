#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q;
string s1[N],s2[N];
int a1[N],a2[N];
string t1,t2;
int len1,len2,len3;
bool flag=true;
bool check(string a,string b)
{
	int len=a.length();
	for(int i=0;i<len;i++)
	{
		if(a[i]!=b[i]) return false;
	}
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		if(flag)
		{
			for(int j=0;j<s1[i].length();j++)
			{
				if((s1[i][j]!='a'&&s1[i][j]!='b')||cnt1>1)
				{
					flag=false;
					break;
				}
				else if(s1[i][j]=='b') a1[i]=j,cnt1++;
				else cnt0++;
			}
			if(cnt1>1) flag=false;
			cnt1=0,cnt0=0;
			for(int j=0;j<s2[i].length();j++)
			{
				if((s2[i][j]!='a'&&s2[i][j]!='b')||cnt1>1)
				{
					flag=false;
					break;
				}
				else if(s2[i][j]=='b') a2[i]=j,cnt1++;
				else cnt0++;
			}
			if(cnt1>1) flag=false;
		}
	} 
	while(q--)
	{
		cin>>t1>>t2;
		len1=t1.length(),len2=t2.length();
		if(len1!=len2)
		{
			cout<<0<<endl;
			continue;
		} 
		int cnt=0;
		if(flag)
		{
			int p1,p2;
			for(int i=0;i<len1;i++)
			{
				if(t1[i]=='b')
				{
					p1=i;
					break;
				}
			}
			for(int i=0;i<len2;i++)
			{
				if(t2[i]=='b')
				{
					p2=i;
					break;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(p1>=a1[i]&&s1[i].length()-a1[i]<=len1-p1)
				{
					if(p1+a2[i]-a1[i]==p2) cnt++;
				}
			}
			cout<<cnt<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			len3=s1[i].length();
			for(int j=0;j<len1-len3+1;j++)
			{
				string t=t1.substr(j,len3);
				if(t==s1[i])
				{
/*					string nxt=t2.substr(j,len3);
					if(s2[i]==nxt) cnt++;*/
					string nxt=t1;
					for(int k=j;k<j+len3;k++) nxt[k]=s2[i][k-j];
					if(nxt==t2) cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
