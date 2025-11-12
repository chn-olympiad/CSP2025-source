#include <bits/stdc++.h>
using namespace std;
char a[1005],m=' ';
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int i,j=1,n;
	cin>>s;
	for(i=0;i<s.size();i++)
	{
        if(s[i]>='0'&&s[i]<='9')
        {
            a[j]=s[i];
            j++;
		}
	}
    for(j=1;j<=s.size();j++)
    {
       for(i=1;i<=s.size();i++)
	{
		if(m<a[i])
		{
            m=a[i];
            n=i;
		}
	}
	a[n]=' ';
	cout<<m;
	m=' ';
	}
	return 0;
}