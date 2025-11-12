#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int a = 1e6+5;
char s[a];
int n[a];
int cnt = 0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	cin>>s;
	int m = strlen(s);
	for(int i = 0;i<m;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n[cnt] = s[i]-'0';
			cnt++;
		}
	}
	sort(n,n+cnt);
	for(int i = cnt-1;i>=0;i--)
	{
		cout<<n[i];
	}
	fclose(stdin);
	fclose(stdout);
}