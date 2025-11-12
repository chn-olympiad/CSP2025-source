#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],t=0;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a,a+t);
	reverse(a,a+t);
	for(int i=0;i<t;i++)
	{
		cout<<a[i];
	}
	return 0;
}
