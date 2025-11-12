#include<bits/stdc++.h>
using namespace std;
struct node
{
	string s1,s2;
	int min1,max1;
	node(string a,string b,int c,int d):s1(a),s2(b),min1(c),max1(d){}
};
unordered_map<string,vector<node> > mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int k=s1.length();
		string str="";
		int min1=INT_MAX,max1=0;
		for(int j=0;j<k;j++)
		{
			if(s1[j]!=s2[j])
			{
				min1=min(min1,j);
				max1=max(max1,j);
			}
		}
		for(int j=min1;j<=max1;j++)
		{
			str+=s1[j];
		}
		for(int j=min1;j<=max1;j++)
		{
			str+=s2[j];
		}
		mp[str].push_back(node(s1,s2,min1,max1));
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length())
		{
			printf("0\n");
			continue;
		}
		int k=s1.length();
		string str="";
		int min1=INT_MAX,max1=0;
		for(int j=0;j<k;j++)
		{
			if(s1[j]!=s2[j])
			{
				min1=min(min1,j);
				max1=max(max1,j);
			}
		}
		for(int j=min1;j<=max1;j++)
		{
			str+=s1[j];
		}
		for(int j=min1;j<=max1;j++)
		{
			str+=s2[j];
		}
		int ans=0;
		for(node j:mp[str])
		{
			int len=j.s1.length();
			int l=min1-j.min1;
			int r=max1+(len-1-j.max1);
			if(l<0||r>=k)
			{
				continue;
			}
			if(s1.substr(l,r-l+1)==j.s1&&s2.substr(l,r-l+1)==j.s2)
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
