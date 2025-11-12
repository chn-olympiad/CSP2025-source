#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N]={-1};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long x=1;
	cin>>s;
	for(long long i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[x]=s[i]-'0';
			x++;
		}
	}
	x--;
	sort(a+1,a+x+1);
	for(long long i=x;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
