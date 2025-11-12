#include <bits/stdc++.h>
using namespace std;
string s;
int n,a;
priority_queue<int> p; 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for (int i=0;i<n;i++)
	{
		if (int(s[i])>=48&&int(s[i])<=57)
		{
			p.push(int(s[i])-48);
			a++;
		}
	}
	for(int i=1;i<=a;i++)
	{
		cout<<p.top();
		p.pop();
	}
	return 0;
 } 
