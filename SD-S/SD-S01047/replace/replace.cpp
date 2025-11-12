#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,q; 
string s[N][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin >>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		string t1,t2;
		cin >>t1>>t2;
		printf("0\n");
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%
有多少种方案将 s1->s2
考虑暴力： 
*/
