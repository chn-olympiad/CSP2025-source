#include <bits/stdc++.h>
using namespace std;
int a[1000001];
bool cmp(int a,int b)
{
	return a > b;
}
int main() 
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int j = 1;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] - '0'>= 0 && s[i] - '0' <= 9)
		{
			a[j] = s[i] - '0';
			j++;
		}
		
	}
	sort(a+1,a+j,cmp);
	for(int i = 1;i < j;i++)
	{
		cout<<a[i];
	}
	return 0;
}
