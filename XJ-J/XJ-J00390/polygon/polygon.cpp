#include<bits/stdc++.h>
using namespace std;
int sum(int a,int b,vector<int>& l)
{
	int sum=0;
	for(int i=a;i<=b;i++)
	{
		sum+=l[i];
	}
	return sum;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,count=0;
	cin>>n;
	vector<int> l(n);
	for(int i=0;i<n;i++)
	{
		cin>>l[i];
	}
	sort(l.rbegin(),l.rend());
	for(int i=3;i<=n;i++)
	{
		for(int j=0;j+i<n;j++)
		{
			int right=j+i-1;
			int left=j+1;
			while(right<n)
			{
				int Sum=sum(left,right,l);
				if(j<Sum)
				{
					left++;
					right++;
					count++;
				}
				else
				{
					break;
				}
			}
		}
	}
	cout<<count%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
 
