#include <bits/stdc++.h>
using namespace std;
int n,q;
int judge(string s1,string s2)
{
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]==s1[0])
		{
			bool flag=1;
			for(int j=0;j<s1.size();j++)
			{
				if(s1[j]!=s2[i+j]) flag=0;
			}
			if(flag) return i;
		}
	}
	return -1;
}
string rep(string s1,string s2,int index)
{
	int len=s2.size();
	for(int i=index;i<index+len;i++)
	{
		s1[i]=s2[i-index];
	}
	return s1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	vector<vector<string>> a(n,vector<string>(2));
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	for(int i=0;i<q;i++) 
	{
		int sum=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int j=0;j<n;j++)
		{
			if(a[j][0].size()>s1.size()) continue;
			if(a[j][0]==s1 and a[j][1]==s2){
				sum++;
				continue;
			}
			int index=judge(a[j][0],s1);
			if(index==-1) continue;
			if(rep(s1,a[j][1],index)==s2) sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}