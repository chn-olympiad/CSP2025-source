#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[100];
	int z = 0;
	cin>>n>>k;
	for(int i = 0;i <= 10;i++)
	{
		cin>>a[i];
		z = z && a[i];
		cout<<z && a[i];
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}