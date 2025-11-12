#include<iostream>
using namespace std;
const int maxn=2e5+1;
int n,q;
string s[maxn][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<"0\n";
			continue;
		}
		long long ans=0;
		for(int i=1;i<=n;i++)//枚举字符串二元组
		{
			if(t1.size()<s[i][1].size())
			{
				continue;
			}
			for(int j=0;j<=t1.size()-s[i][1].size();j++)//初始位置
			{
				bool f=0;
				string s1=t1;
				for(int k=0;k<s[i][1].size();k++)//逐位对比
				{
					if(s[i][1][k]!=t1[j+k])
					{
						f=1;
						break;
					}
					s1[j+k]=s[i][2][k];
				}
				if(s1==t2)
				{
					++ans;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}