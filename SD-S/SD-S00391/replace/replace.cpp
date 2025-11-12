#include <bits/stdc++.h>
using namespace std;
int n,q;
long long ans;
string s1[200010],s2[200010],q1,q2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		ans=0;
		cin>>q1>>q2;
		for(int i=1;i<=n;i++)
		{
			if(q1.find(s1[i])<5000010)
			{
				int a=q1.find(s1[i]);
				string ss;
				for(int j=0;j<q1.length();j++)
				{
					if(j<a)
					{
						ss+=q1[j];
					}
					if(j>a+s1[i].length()-1) 
					{
						ss+=q1[j];
					}
					if(j>=a && j<=a+s1[i].length()-1)
					{
						ss+=s2[i][j-a];
					}
				}
				if(ss==q2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

