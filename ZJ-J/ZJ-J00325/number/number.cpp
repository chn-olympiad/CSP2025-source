#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string a;
	cin>>a;
	int n = 0;
	vector<int> l;
	int m = a.size();
	for(int i = 0;i<a.size();i++)
	{
		if(a[i] >= '0'&& a[i] <='9')
		{
			int la = a[i]-'0';
			l.push_back(la);
			n++;
		}
	}
	sort(l.begin(),l.end());
	for(int i = n-1;i>=0;i--)
	{
		cout<<l[i];
	}

	return 0;
}
