#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<stack>
using namespace std;
const int N=11;
string s;
int a[N],n,i,j;
int main()
{
	ios::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		a[s[i]-'0']++;
	}
	for(i=9;i>=0;i--)
	{
		for(j=1;j<=a[i];j++)
		cout<<i;
	}
	return 0;
}
