//SN-J00811 王雅宁 西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],z=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i = 0;i<n;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[z]=s[i]-'0';
			z++;
		}
	}
	sort(a,a+n,cmp);
	for(int i = 0;i<z;i++)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
