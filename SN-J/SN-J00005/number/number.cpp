#include<bits/stdc++.h>
using namespace std;
string a;
int n[10];
bool k=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int s=a.size();
	for(int i=0;i<=s;i++)
	{
		if(!(a[i]>='0'&&a[i]<='9'))continue;
		int num=a[i]-='0';
		n[num]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=n[i];j++)
			cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
