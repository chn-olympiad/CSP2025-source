#include<bits/stdc++.h>
using namespace std;
int s[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,l,cnt=0;
	string a;
	cin>>a;
	l=a.size();
	for(i=0;i<=l-1;i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			s[i]=a[i]-'0';
			cnt++;
		}
	}
	sort(s,s+l,cmp);
	for(i=0;i<=cnt-1;i++)
	{
		cout<<s[i];
		
	}
	return 0;
 } 
