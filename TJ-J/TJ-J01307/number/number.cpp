#include <bits/stdc++.h>
using namespace std;
string s;
string arr[100001];
string ss="0123456789";

bool cmp(string a,string b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int c=0;

	
	for(int i=0;i<s.length();i++)
	{
		if(ss.find(s[i])>=0&&ss.find(s[i])<=9)
		{
			arr[c]=s[i];
			c++;
		}
	}
	
	
	sort(arr,arr+c,cmp);
	
	for(int i=0;i<c;i++)
	{
		cout<<arr[i];
	}
	
	return 0;
 }
 


