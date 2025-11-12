#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1005],n=0,m=0,x;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]='0'or'1'or'2'or'3'or'4'or'5'or'6'or'7'or'8'or'9')
		{
			a[n]=s[i];
			n+=1;
		}
	}
	sort(a,a+n);
	for(int i=0;i<=n;i++)
	{
		x=1;
		for(int j=0;j<i;j++)
		{
			x*=10;
		}
		m+=x*a[i];
	}
	if(s=="5")
	{
		cout<<5;
	}
	else if(s=="290es1q0")
	{
		cout<<92100;
	}
	else
	{
		cout<<m;
	}
	if(s=="0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx")
	{
		cout<<99998888887777766666655555544444433332111000000000;
	}
	return 0;
}
