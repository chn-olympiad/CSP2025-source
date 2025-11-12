#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool compare(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fill(a,a+1000010,-1);
	string s;
	cin>>s;
	int t=s.size(),p=1;
	for(int i=0;i<t;++i)
	{
		if(isdigit(s[i]))
		{
			a[p]=s[i]-'0';
			++p;
		}
	}
	sort(a,a+1000010,compare);
	for(int i=0;i<p-1;++i)
		cout<<a[i];
	return 0;
} 
