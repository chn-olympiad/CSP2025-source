#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[1100001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int temp=0;
	string s;
	cin >> s;
	for(long unsigned int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++temp]=s[i]-'0';
		}
	}
	sort(a+1,a+temp+1);
	if(a[temp]==0)
	{
		cout << 0;
		return 0;
	}
	for(int i=temp;i>=1;i--)
	{
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
 } 
