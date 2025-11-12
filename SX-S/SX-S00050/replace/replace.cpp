#include<bits/stdc++.h>
using namespace std;
string s1[200010],s2[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string t1,t2,s,ss;
	long long n,q,sum=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		cin>>t1>>t2;

		s="";
		ss="";
		for(int i=0;i<=t1.size()-1;i++)
		{
			if(t1[i]!=t2[i])
			{
				s=s+t2[i];
				ss=ss+t1[i];


			}
		}
		for(int i=1;i<=n;i++)
		{
			if(ss==s1[i]&&s==s2[i])
			{
				sum++;
			}
		}

	}
	cout<<sum;




	return 0;
}