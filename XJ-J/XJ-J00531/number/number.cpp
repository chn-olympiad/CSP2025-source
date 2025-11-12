#include<bits/stdc++.h>
using namespace std;
int a[1000005],t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int z=s.size();
	for(int i=0;i<z;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			t++;
			a[t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1);
	for(int i=t;i>0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
