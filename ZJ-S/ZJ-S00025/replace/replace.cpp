#include<bits/stdc++.h>
using namespace std;
int maxn,n,q,ji;
struct node
{
	string s1,s2;
}s[10005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].s1>>s[i].s2;
	}
	while(q--)
	{
		string s1,s2; cin>>s1>>s2;
		int lon=s1.size()+1;
		s1=' '+s1;
		s2=' '+s2;
		int cnt=0;
		for(int i=1;i<=lon-1;i++)
		{
			for(int j=i+1;j<=lon;j++)
			{
				bool p=1;
				for(int k=1;k<=i-1;k++)
				{
					ji++;
					if(s1[k]!=s2[k])
					{
						p=0; break;
					}
				}
				for(int k=j+1;k<=n;k++)
				{
					ji++;
					if(s1[k]!=s2[k])
					{
						p=0;
						break;
					}
				}
				if(!p) continue;
				string l1,l2;
				for(int k=i;k<=j;k++)
				{
					ji++;
					l1=l1+s1[k],l2=l2+s2[k];
				}
				//cout<<l1<<" "<<l2<<endl;
				for(int k=1;k<=n;k++)
				{
					ji++;
					if(s[k].s1==l1&&s[k].s2==l2)
					{
						cnt++; break;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	cout<<ji;
	return 0;
}
