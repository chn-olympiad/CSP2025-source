#include <bits/stdc++.h>
using namespace std;
long long huang[10000][10000],c[3][10000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int sum=0;
		int n;
		cin>>n;
		int A=1,B=1,C=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>huang[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(huang[i][1]>huang[i][2])
			{
				if(huang[i][1]>huang[i][3])
				{
					c[1][A]=huang[i][1];
					A++;
				}
			}
			if(huang[i][2]>huang[i][1])
			{
				if(huang[i][2]>huang[i][3])
				{
					c[2][B]=huang[i][2];
					B++;
				}
			}
			if(huang[i][3]>huang[i][2])
			{
				if(huang[i][3]>huang[i][1])
				{
					c[3][C]=huang[i][3];
					C++;
				}
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=max(A,max(B,C))-1;j++)
			{
				sum+=c[i][j];
			}
		}
		cout<<sum<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}