#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int t=0;
	cin>>s;
	int n=s.size();
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i]-'0';
			t++;
		}
	}
	sort(a,a+n);
	string s1="";
	for(int i=n-1;i>=n-t;i--)
	{
		s1+=(a[i]+'0');
	}
	cout<<s1;
	
	return 0;
}
