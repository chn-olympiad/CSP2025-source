#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int num[1000010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	int p=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			num[++p]=s[i]-'0';
	}
	sort(num+1,num+1+p);
	for(int i=p;i>=1;i--)
	{
		cout<<num[i];
	}
	return 0;
}
