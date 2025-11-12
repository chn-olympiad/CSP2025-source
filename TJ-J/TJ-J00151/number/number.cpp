#include<bits/stdc++.h>
using namespace std;
	char a[100005];
	int b;
	int num[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>a;
	for(int i=0;i<100000;i++)
	{
		
		if(((int(a[i]))>=47)&&((int(a[i])<=57)))
		{
			num[int(a[i])-48]++;
		}

	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<num[i];)
		{
			cout<<i;
			num[i]--;
		}
	}

	return 0;
	
	
	
	
}
