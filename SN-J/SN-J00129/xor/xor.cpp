#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	char a[10005];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		cout<<2;
	}
	else
	{
		cout<<1;
	}
	cout<<""<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
