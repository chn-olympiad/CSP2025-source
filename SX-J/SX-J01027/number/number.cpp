#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000005];
int t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			c[t]=s[i];
			t++;
		}
	}
	sort(c,c+t);
	for(int i=t-1;i>=0;i--) cout<<c[i];
	return 0;
}
