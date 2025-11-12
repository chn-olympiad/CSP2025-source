#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int stick[N];
int sum[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>stick[i];
	}
	sort(stick+1,stick+1+n);
	if(stick[1]+stick[2]>stick[3])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
		
	return 0;
}
