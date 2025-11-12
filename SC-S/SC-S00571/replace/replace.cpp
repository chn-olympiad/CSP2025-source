#include <bits/stdc++.h>
using namespace std;
int n,q,key,num[200010],ans;
string s1[200010],s2[200010],l1,l2,l3;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l1>>l2;
		for(int j=1;j<=n;j++)
		{
			l3=l1;
			key=0;
			while(l3.find(s1[j])!=18446744073709551615)
			{
				key++;
				num[key]=l3.find(s1[j]);
				l3[num[key]]='0';
			}
			for(int p=1;p<=key;p++)
			{
				l3=l1;
				for(int k=num[key];k<=num[key]+s1[j].size()-1;k++)
				{
					l3[k]=s2[j][k-num[key]];
				}
				if(l3==l2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 