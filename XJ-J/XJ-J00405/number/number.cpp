#include<bits/stdc++.h>
using namespace std;
string a;
int f[13];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int s=a.size()-1;
    for(int i=0;i<=s;i++)
    {
    	if(a[i]-'0'>=0&&a[i]-'0'<=9)
    	{
    		f[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=f[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
 } 
