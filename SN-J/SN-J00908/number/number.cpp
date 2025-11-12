#include <bits/stdc++.h>
using namespace std;
string s;
int num[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int bj=s[i]-'0';
			cnt++;
			num[cnt]=bj;
		}
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		cout<<num[i];
	}
	return 0;
}
