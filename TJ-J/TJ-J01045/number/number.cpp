#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a[100001]={};
	int cnt=0,b[1005]={},c=1;
	while (a[c]!="0/")
	{
		c++;
		cin>>a[c];
		if(a[c]=='0'||a[c]=='1'||a[c]=='2'||a[c]=='3'||a[c]=='4'||a[c]=='5'||a[c]=='6'||a[c]=='7'||a[c]=='8'||a[c]=='9')
		{
			b[cnt]=a[c];
			cnt++;
		}
	}
	sort(b,b+cnt);
	for(int i=cnt;i>=1;i--)
	{
		cout<<b[i];
	}		
} 
