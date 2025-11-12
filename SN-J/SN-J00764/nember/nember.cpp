#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000001];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("nember.in","r",stdin);
	freopen("nember.out","w",stdout);
	cin>>s;
	int n=s.size();
	int u=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++u]=s[i]-'0';
		}
	}
	sort(a+1,a+u+1,cmp);
	for(int i=1;i<=u;i++)
	{
		printf("%d",a[i]);	
	}	
	return 0;
}
