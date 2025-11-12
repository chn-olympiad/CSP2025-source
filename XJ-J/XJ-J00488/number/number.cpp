#include<bits/stdc++.h>
using namespace std;
string s;
char arr[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a=0;
	getline(cin,s);
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			arr[a]=s[i];
			a++;
		}
	}
	sort(arr,arr+a);
	for(int i=a-1;i>=0;i--)
	{
		cout<<arr[i];
	}
	return 0;
}
