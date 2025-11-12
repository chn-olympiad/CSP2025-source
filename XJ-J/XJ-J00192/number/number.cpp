#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[505];
	int n=0;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
	    if(s[i]>='0'&&s[i]<='9')
	    {
	    	a[i]=s[i];
	    	n++;
		}
	}
	for(int i=n;i>=0;i--)
	{
		sort(a,a+i+1);
		cout<<a[i];
	}
	return 0;
}
