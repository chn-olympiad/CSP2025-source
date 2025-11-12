#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,q,t,ans;
vector<string>a,b,c,d;
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		a.push_back(s1);b.push_back(s2);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		c.push_back(s1);d.push_back(s2);
	}
	for(int i=0;i<c.size();i++)
	{
		ans=0;
		for(int j=0;j<a.size();j++)
		{
			s1=c[i],s2="";
			t=s1.find(a[j]);
			while(t!=-1)
			{
				for(int k=0;k<t;k++) s2+=s1[k];
				string w=s2+b[j];
				for(int l=t+a[j].length();l<s1.length();l++)w+=s1[l];
				if(w==d[i]) {ans++;break;}
				s2+=s1[t];w="";
				for(int k=t+1;k<s1.length();k++)w+=s1[k];
				s1=w;
				t=s1.find(a[j]);
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
