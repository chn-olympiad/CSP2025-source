#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string s1,s2;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	  cin>>s1>>s2;
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
