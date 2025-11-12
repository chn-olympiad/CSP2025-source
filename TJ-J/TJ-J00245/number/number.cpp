#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int cnt=0;
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i];
			a[i]-=42;
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<=cnt-1;i++)
	{
		cout<<a[i];
	}
	
	return 0;
} 
