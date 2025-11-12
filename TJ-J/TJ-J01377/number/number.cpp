#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ss=s.size();
	int sa=0;
	for (int i=0;i<ss;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			sa++;
			a[sa]=s[i]-='0';
			
		}
	}
	sort(a+1,a+sa,cmp);
	int cnt=0;
	for (int i=1;i<=sa;i++)
	{
		cout<<a[i];		
	}
	return 0;
 } 
