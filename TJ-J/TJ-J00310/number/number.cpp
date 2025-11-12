#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string s;
int n[10000005],sum;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int xx=1;
	for(int i=0;i<s.size();i++)
	{
		int maxx=-1e9;
		int id=0;
		for(int j=0;j<=i;j++)
		{
			if(s[j]>='0'&&s[j]<='9')
			{
				maxx=max(maxx,s[j]-'0');
				id=j;
				n[xx]=maxx;
				xx++;
			}
			s[id]='a';
			continue;
		}
	}
	for(int i=1;i<xx;i++)
	{	
		int idd=0,m=-1e9;
		for(int j=0;j<xx;j++)
		{
			if(n[j]>=0)
			{
				m=max(m,n[j]);
			}	
		} 
		for(int j=0;j<xx;j++)
		{
			if(n[j]==m)
			{
				idd=j;
				break;
			}
		}
		sum=sum*10+m;
		n[idd]=-1;
	}
	cout<<sum;
	return 0;
}
