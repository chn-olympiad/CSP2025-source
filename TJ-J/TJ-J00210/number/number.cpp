#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len = s.length(),i,j=0;
	for(i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			j++;
			a[j] = s[i]-'0';
		}
	}
	sort(a+1,a+1+j,cmp);
	for(i=1;i<=j;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
