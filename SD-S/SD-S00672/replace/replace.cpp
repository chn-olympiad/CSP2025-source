#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio> 
using namespace std;
string s1[200005],s2[200005];
int pos[200005],l[200005],r[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans=0,pos1,pos2,cnt1=0,cnt2=0;
	string t1,t2;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++)
		{
			if(s1[i][j]=='b')
			{
				pos1=j;
				cnt1++;
			}
		}
		for(int j=0;j<s2[i].size();j++)
		{
			if(s2[i][j]=='b')
			{
				pos2=j;
				cnt2++;
			}
		}
		l[i]=pos1;
		r[i]=s1[i].size()-pos1-1;
		pos[i]=pos2-pos1;
	}
	if(n<=10&&q<=10)
	{
		for(int i=1;i<=q;i++)
		{
			ans=0;
			cin>>t1>>t2;
			for(int j=1;j<=n;j++)
			{
				if(t1.find(s1[j])==string::npos)continue;
				int p=t1.find(s1[j]);
				string s;
				s=t1.substr(0,p)+s2[j]+t1.substr(p+s1[j].size(),t1.size()-p-s1[j].size());
	//			cerr<<t1.substr(0,p)<<" "<<s1[j]<<" "<<t1.substr(p+s1[j].size(),t1.size()-p-s1[j].size())<<endl;
				if(s==t2)ans++;
			}
			cout<<ans<<"\n";
		}
	}
	else if(cnt1==n&&cnt2==n)
	{
		for(int i=1;i<=q;i++)
		{
			cin>>t1>>t2;
			pos1=t1.find('b');
			pos2=t2.find('b');
			for(int j=1;j<=n;j++)
			{
				if(pos2-pos1==pos[i]&&pos1>=l[i]&&t1[i].size()-pos1-1<=r[i])
				{
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	else
	{
		cout<<0<<endl;
	}
	cout<<endl;
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
