#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string st;
int numm[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.length();i++)
	{
		if(st[i]>='0'&&st[i]<='9')numm[st[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(numm[i]>0)
		{
			numm[i]--;
			cout<<i;
		}
	}
	return 0;
}
