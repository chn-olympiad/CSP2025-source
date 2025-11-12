#include<bits/stdc++.h>
using namespace std;
string s;
const int M=1e7+5;
int a[M];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int p=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[p]=s[i]-'0';
			p++;
		}
	}
	sort(a+1,a+p,greater<int>());
	for(int i=1;i<=p-1;i++)
	{
		cout<<a[i];
	}
	return 0;
}
