#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string a[N],b[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int pos=s1.find(a[i]);
			if(pos!=-1)
			{
				string s3=s1;
				for(int j=0;j<a[i].size();j++)
				{
					s3[j+pos]=b[i][j];
				}
				if(s3==s2)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
