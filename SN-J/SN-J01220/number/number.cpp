//SN-J01220 龚西贝 西安建筑科技大学附属中学
#include<bits/stdc++.h>
using namespace std;
bool xy(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if('0'<=a[i]&&a[i]<='9')
		{
			b.push_back(a[i]);
		}
	}
	if(b.empty())
	{
		return 0;
	}
	sort(b.begin(),b.end(),xy);
	cout<<b;
	return 0;
}
