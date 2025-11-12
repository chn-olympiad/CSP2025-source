#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	string s;
	long long a[100005];
	int r=1;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[r]=s[i]-48;
			r++;
		}
	}
	r=r-1;
    sort(a+1,a+1+r,cmp); 
    for(int i=1;i<=r;i++)
	{
		cout<<a[i];
	}
	return 0;
 } 
