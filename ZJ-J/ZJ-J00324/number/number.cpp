#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],num=1;
void bubble()
{
	bool fll=0;
	for(int i=1;i<num;i++)
	{
		for(int j=1;j<=num-i;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
				fll=1;
			}
		}
		if(fll==0)
		{
			return ;
		}
	}
	return ;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[num]=s[i]-'0';
			num++;
		}
	}
	bubble();
	for(int i=1;i<num;i++)
	{
		cout<<a[i];
	}
	return 0;
}

