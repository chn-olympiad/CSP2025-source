#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	vector<int> l;
	long long ans;
	
	for(int i = 0;i<n;i++)
	{
		int a;
		cin>>a;
		l.push_back(a);
	}
	
	sort(l.begin(),l.end());
	
	for(int i = 3;i<n;i++)
	{
		for(int j = n-1;i>=0;j++)
		{
			for(int j = n-1;i>=0;j++)
			{
			
			}
		}
	}
	
	return 0;
}
