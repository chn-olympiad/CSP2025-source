#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string s1[200005];
string s2[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int l=0;l<t1.size();l++)
		{
			for(int r=l;r<t2.size();r++)
			{
				string t3="",t4="";
				for(int ii=0;ii<l;ii++)
				{
					t3=t3+t1[ii];
					t4=t4+t2[ii];
				}
				if(t3!=t4) continue;
				t3="",t4="";
				for(int ii=r+1;ii<t1.size();ii++)
				{
					t3=t3+t1[ii];
					t4=t4+t2[ii];
				}
				if(t3!=t4) continue;
				t3="",t4="";
				for(int ii=l;ii<=r;ii++)
				{
					t3=t3+t1[ii];
					t4=t4+t2[ii];
				}
				for(int ii=0;ii<n;ii++)
				{
					if(t3==s1[ii]&&t4==s2[ii]) cnt+=1;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
