#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int t;
const int  m= 1e5+5;
int a[m][4],n;
int main()
{
 	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--)
	{
		int n;
		cin>>n;
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<3;j++)
			{
    			cin>>a[i][j];
			}
		}
		int maxn = 0,cnt = 0;
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<3;j++)
			{
    			if(a[i][j]>=maxn)
				{
    				maxn = a[i][j];
				}
			}
            cnt+=maxn;
			maxn = 0;
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
