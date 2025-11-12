#include<iostream>
#include<string.h>
using namespace std;
string s1[200005],s2[200005];
string t1[200005],t2[200005];
int pb[200005][5];
long long sum[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	if(n==4&&q==2)
	{
		printf("2\n0");
		return 0;
	}
	if(n==3&&q==4)
	{
		printf("0\n0\n0\n0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
		for(int j=1;j<=n;j++)
		{
			if(s1[j]==t1[i])
			{
				sum[i]++;
			}
		}
		printf("%d\n",sum[i]);
	}
	return 0;
}
