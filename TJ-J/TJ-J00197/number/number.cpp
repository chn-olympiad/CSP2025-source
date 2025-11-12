#include<bits/stdc++.h>
using namespace std;
int b[1000005];
bool han(int x,int y)
{
	if(x>y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int j=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b,b+j,han);
	for(int i=0;i<j;i++)
	{
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
 } 
