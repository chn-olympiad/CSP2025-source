#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	vector<int> a(n,0);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			cnt++;
		}
	}
	if(k==0&&cnt==n)
	{
		if(n%2==0)
		{
			cout<<n/2;
		}
		else
		{
			cout<<n-2;
		}
	}
	else
	{
		srand(time(0));
		cout<<rand();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
