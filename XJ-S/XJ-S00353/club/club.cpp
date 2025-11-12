#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=1e4+5;
int a[mod];
int f[mod];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	int n;
	int sum=0;
	int cnt=0;
	int maxn;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			maxn=0;
			cnt=0;
			for(int j=1;j<=3;j++)
			{
				int k;
				cin>>k;
				maxn=max(maxn,k);
			}
			sum+=maxn;
		}
//		for(int i=1;i<=n;i++)
//		{
//			cin>>a[i];
//		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=3;j++)
//			{
//				if(cnt<n/2)
//				{
//					int q=0;
//					q++; 
//					if(t[i-q][j]>max1)
//					{
//						max1=t[i-q][j];
//						cnt++;
//					}
//					if(t[i][j-q]>max2)
//					{
//						max2=t[i][j-q];
//						cnt++;
//					}
//					int tot=(max1+max2)*2;
//				}
//			}
//			sum+=tot;
//		} 
		cout<<sum<<endl;
		return 0;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

