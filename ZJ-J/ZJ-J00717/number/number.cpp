#include <bits/stdc++.h>
using namespace std;
string s;
int a[20],len,d;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(i!=0&&a[i]>0)
		d=1;
		if(i==0&&d==0)
		a[0]=1;
		for(int j=1;j<=a[i];j++)
		cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
