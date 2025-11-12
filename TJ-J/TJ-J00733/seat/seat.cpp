include <bits/stdc++.h>
using namespace std;
int o[100];
int n,m;
int nh,mh;
int main()
{
	cin>>n>>m;
	for (int i=0;i<n*m;i++)
	{
		cin>>o[i];
	}
	int hua=o[0];
	while (o[0]=100)
	{
		int i=0
		if (o[i]<=o[i+1])
		{
			int a=o[i];
			o[i]=o[i+1];
			o[i+1]=a;
		}
		i++;
	}
	for (int i=0;i<n*m;i++)
	{
		
	}
	return 0;
}

