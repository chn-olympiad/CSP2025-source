#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],j=1,ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int b=int(s[i])-48;
			a[j]=b;
			j++;
		}
	}
	sort(a+1,a+j+1);
	if(a[j]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=j;i>1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
