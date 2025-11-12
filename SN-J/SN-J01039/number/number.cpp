#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],ai;
priority_queue<int> q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			int x=s[i]-'0';
			q.push(x);
		}
	}
	while(!q.empty())
	{
		a[++ai]=q.top();
		q.pop();
	}
	for(int i=1;i<=ai;i++)
	{
		cout<<a[i];
	}
	cout<<"\n";
	return 0;
}
