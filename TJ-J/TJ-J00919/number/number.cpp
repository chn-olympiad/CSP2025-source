#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<map>
#include<deque>
#include<set>
#define ll long long
using namespace std;
const int N=1000005;
string c;
char a[N];
bool cmp(char x,char y)
{
	return x>y;
} 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	int n=c.size();
	c=" "+c;
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			a[cnt]=c[i];
			cnt++;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}

