#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<cstdio>
#include<string.h>
using namespace std;
const int N=1e6+10;
char s[N];
long long int num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if((s[i]-'0')>=0 && (s[i]-'0')<=9)
		{
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(num[i]>0)
		{
			cout<<i;
			num[i]--;
		}
	}
 	return 0;
}
