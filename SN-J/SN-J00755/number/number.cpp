#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
int num[maxn];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			num[++cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		printf("%d",num[i]);
	}
	return 0;
} 
