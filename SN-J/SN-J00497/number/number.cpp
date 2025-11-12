//SN-J00497 李中易 西安辅轮中学
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int n,ans[10]; 

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;n=s.size();
	for(int i=0;i<n;i++)  if('0'<=s[i]&&s[i]<='9')  ans[s[i]-'0']++;
	for(int i=9;i>=0;i--)  for(int j=1;j<=ans[i];j++)  cout<<i;
	return 0;
}

