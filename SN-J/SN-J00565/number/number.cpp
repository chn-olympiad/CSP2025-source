#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int a[10]={};
	for(int i=0;i<n.size();i++)
	{
		if(n[i]>='0'&&n[i]<='9') a[(n[i]-48)]+=1;
	}
	for(int i=9;i>=0;i--) for(int j=0;j<a[i];j++) cout<<i;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
