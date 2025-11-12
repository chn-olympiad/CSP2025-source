#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
string s;
long long t=0;
long long a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
