#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,a[100005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int j=cnt;j>=1;j--)
	{
		cout<<a[j];
	}
}
