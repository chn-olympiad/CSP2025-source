#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	priority_queue<char> q;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			q.push(s[i]);
		}
	}
	while(q.size())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}