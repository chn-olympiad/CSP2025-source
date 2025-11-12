#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b[15]={},ans=0;
	cin>>a;
	for(int i=0;i<a.size()+1;i++)
		if(a[i]<='9'&&a[i]>='0')
		{
			b[int(a[i]-'0')]++;
		}
	for(int i=9;i>=0;i--)
		for(int j=0;j<b[i];j++)
			cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}