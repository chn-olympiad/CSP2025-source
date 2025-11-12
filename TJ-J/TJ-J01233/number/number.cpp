#include<bits/stdc++.h>
using namespace std;
string a;
vector<long long> shu;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>a;
	bool flag = true;
	for(long long i = 0;i<a.size();i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			if(a[i]!='0')
			{
				flag = false;
			}
			shu.push_back(a[i]-'0');
		}
	}
	if(flag)
	{
		cout<<0;
	}
	else
	{
		sort(shu.begin(),shu.end(),cmp);
		for(long long i = 0;i<shu.size();i++)
		{
			cout<<shu[i];
		}
	}
	cout<<endl;
	return 0;
}
