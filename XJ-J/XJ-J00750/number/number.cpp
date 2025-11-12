#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005]={-1};
int num=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=' '+s;
	int len = s.size();
	for(int i = 1;i < len;i++)
	{
		if(s[i]=='0')
		{
			num++;
			a[num]==0;
		}
		else if(s[i]=='1')
		{
			num++;
			a[num]=1;
		}
		else if(s[i]=='2')
		{
			num++;
			a[num]=2;
		}
		else if(s[i]=='3')
		{
			num++;
			a[num]=3;
		}
		else if(s[i]=='4')
		{
			num++;
			a[num]=4;
		}
		else if(s[i]=='5')
		{
			num++;
			a[num]=5;
		}
		else if(s[i]=='6')
		{
			num++;
			a[num]=6;
		}
		else if(s[i]=='7')
		{
			num++;
			a[num]=7;
		}
		else if(s[i]=='8')
		{
			num++;
			a[num]=8;
		}
		else if(s[i]=='9')
		{
			num++;
			a[num]=9;
		}
	}
	sort(a+1,a+num+1);
	for(int i = num;i > 0;i--)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
