//SN-J00534 高新二中 李昊泽 
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
string s;
string s1; 
int ans=0;
//int a[1000050];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			q.push(s[i]-'0');
		} 
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0; 
}
