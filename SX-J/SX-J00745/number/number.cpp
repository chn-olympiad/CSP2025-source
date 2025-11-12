#include<bits/stdc++.h>
using namespace std;
char c;
int a[1000005],aaa;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c)if(c>='0'&&c<='9')a[aaa]=c-'0',aaa++;
	sort(a,a+aaa,cmp);
	for(int i=0;i<aaa;i++)cout<<a[i];
	return 0;
}