#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000000]={0},j=0,m=0,n=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(!('a'<=s[i]&&'z'>=s[i]))
		{
			a[j]=s[i];
			j++;
		}
	}
	for(int i=0;i<j+1;i++)
	{
		for(int z=0;z<j+1;z++)
		{
			if(a[z]>=m)
			{
				m=a[i];
				n=z;
			}
		}
		cout<<m<<endl;
		a[n]=0;
	}
	return 0;
}
