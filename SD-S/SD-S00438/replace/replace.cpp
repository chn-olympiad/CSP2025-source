#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node
{
	string str1,str2;
	int sz;
};
node a[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].str1>>a[i].str2;
		a[i].sz=a[i].str1.size();
	}
	string s1,s2;
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			cout<<"0\n";
			continue;
		}
		const int len=s1.size();
		vector<int> df(len,0);
		if(s1[0]!=s2[0])
			df[0]=1;
		for(int i=1;i<len;i++)
			df[i]=df[i-1]+(s1[i]!=s2[i]);
		for(int j=1;j<=n;j++)
		{
			set<int> s;
			int pos=0;
			while((pos=s1.find(a[j].str1,pos))!=string::npos)
			{
				s.insert(pos);
				pos+=a[j].sz;
			}
			pos=0;
			while((pos=s2.find(a[j].str2,pos))!=string::npos)
			{
				if(s.count(pos)&&(df[pos+a[j].sz-1]==df[len-1])&&(pos==0||(df[pos-1]==0)))
					ans++;
				pos+=a[j].sz;
			}
		}
		cout<<ans<<"\n";
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
