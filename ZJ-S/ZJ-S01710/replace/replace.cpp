#include<bits/stdc++.h>
using namespace std;
long long n,q,p=1,ans,x1[5000100],x2[5000100],xx1,xx2,xx3,s3[5000100],l1[5000100],l2[5000100];
string ss1,ss2,s1,s2;
int main( )
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		s1="";
		s2="";
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++)
		{
			if(s1[j]=='b')
			{
				x1[i]=j;
			}
			if(s1[j]!='a'&&s1[j]!='b')
			{
				p=0;
			}
		}
		for(int j=0;j<s2.size();j++)
		{
			if(s2[j]=='b')
			{
				x2[i]=j;
			}
			if(s2[j]!='a'&&s2[j]!='b')
			{
				p=0;
			}
		}
		l1[i]=s1.size();
		l2[i]=s2.size();
		s3[i]=x1[i]-x2[i];
	}
	//for(int i=1;i<=n;i++)
	//{
	//	cout<<s3[i]<<' ';
	//}
	while(q--)
	{
		ss1="";
		ss2="";
		cin>>ss1>>ss2;
		ans=0;
		if(p==1)
		{
			for(int i=0;i<ss1.size();i++)
			{
				if(ss1[i]=='b')
				{
					xx1=i;
				}
			}
			for(int i=0;i<ss2.size();i++)
			{
				if(ss2[i]=='b')
				{
					xx2=i;
				}
			}
			xx3=xx1-xx2;
			//cout<<xx3<<' ';
			for(int i=1;i<=n;i++)
			{
				if(xx3==s3[i]&&xx1>=x1[i]&&xx2>=x2[i]&&(l1[i]-x1[i])<=(ss1.size()-xx1)&&(l2[i]-x2[i])<=(ss2.size()-xx2))
				{
					ans+=1;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
//tui yi
//QwQ
