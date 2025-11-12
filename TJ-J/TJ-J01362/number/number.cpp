#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<int> > q;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.length();i++)
	{
		s[i]-=48;
	}
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==0||s[i]==1||s[i]==2||s[i]==3||s[i]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||s[i]==9)
		{
			q.push(s[i]);
		}
	}
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}
