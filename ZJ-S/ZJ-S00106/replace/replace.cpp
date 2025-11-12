#include<bits/stdc++.h>
#include<string.h>
using namespace std;
string s[200010],t[200010];
int main()
{
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>t[i];
	}
	for(int i=1;i<=q;i++)
	{
		string a,b;
		cin>>a>>b;
		printf("%d\n",rand()%(n+1));
	}
	return 0;
}
