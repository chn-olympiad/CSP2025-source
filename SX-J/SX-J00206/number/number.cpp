#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char num[100];
	char count = 0;
	for(int i = 0;i <= 10;i++)
	{
		cin>>num[i];
		if('0' <= num[i] && num[i]<= '9')
		{
			cout<<num[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}