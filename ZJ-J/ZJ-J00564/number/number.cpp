#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	string s;
	for(int i=0;i<a.size();i++)
	{
		if('0'<=a[i] && a[i]<='9')
		{
			s.push_back(a[i]);
		}
	}
	sort(s.rbegin(),s.rend());
	cout<<s;
	return 0;
}
