#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s[200005][3],t1,t2;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		cin>>t1>>t2;
		long long num=0;
		for(int i=1;i<=n;i++)
		{
			int op=1;
			string s1="",s2="";
			int l1=t1.size(),L=s[i][1].size(),j;
			bool f1=0;
			for(j=0;j<l1-L;j++)
			{
				bool f=1;
				if(t1[j]==s[i][1][0])
				{
					for(int k=j;k<=j+L;k++)
					{
						if(t1[k]!=s[i][1][k-j])
						{
							f=0;
							break;
						}
					}
				}
				if(f)
				{
					f1=1;
					break;
				}
				s1+=t1[j];
			}
			for(j+=L;f1&&j<l1;j++)
			{
				s2+=t1[j];
			}
			if(f1&&s1+s[i][2]+s2==t2)num++;
		}
		cout<<num<<"\n";
	}
	//做不来QwQ 
	return 0;
}