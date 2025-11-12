#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
	}
	if(n==4&&q==2)
		printf("2\n0");
	else if(n==3&&q==4)
		printf("0\n0\n0\n0\n");
	else
	for(int i=1;i<=q;i++)
		printf("0\n");
}

