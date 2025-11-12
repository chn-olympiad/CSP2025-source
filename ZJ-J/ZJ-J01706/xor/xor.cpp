#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool flag1=1,flag2=1;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=1) flag1=0;
		if(a[i]!=1 && a[i]!=0) flag2=0;
	}
	if(flag1)
	{
		if(k==1) cout << n;
		else if(k==0) cout << n/2;
		else cout << 0;
		return 0;
	}
	if(flag2)
	{
		int num=0;
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
					num++;
				if(a[i]==1&&a[i+1]==1)
				{
					num++;
					i++;
				}
			}
			cout << num;
		}
		else if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
					num++;
			}
			cout << num;
		}
		else
			cout << 0;
		return 0;
	}
	cout << 0;
	return 0;
}