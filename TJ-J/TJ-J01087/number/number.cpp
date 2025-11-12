#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	if(x>=y)
	{
		return true;
	}
	else
		return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[100006];
	cin>>s;
	int q=s.size();
	int c=0;
	for(int i=0;i<q;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a[c]=s[i]-'0';
			c++;
		}
	}
	sort(a,a+c,cmp);
	for(int i=0;i<c;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
