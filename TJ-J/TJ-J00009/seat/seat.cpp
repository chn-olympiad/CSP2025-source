#include<bits/stdc++.h>
using namespace std;
int n,m;
int nums[110];
int ans[11][11];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k = 0;
    int len = n*m;
    for(int i = 1;i<=len;i++) cin>>nums[i];
	int flag = nums[1];
	sort(nums+1,nums+1+len,cmp);
	//a1Îª³É¼¨
	int q = 0;
	for(int i = 1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j = 1;j<=n;j++)	{
				q+=1;
				ans[j][i] = nums[q]; 
			}
		}
		else{
			for(int j = n;j>=1;j--)
			{
				q+=1;
				ans[j][i]=nums[q];
			}
		}
	} 
	for(int i = 1;i<=n;i++)
	{
	 	for(int j = 1;j<=m;j++)
	 	{
	 		if(ans[i][j]==flag)
	 		{
	 			cout<<j<<" "<<i;
	 			return 0;
			}
		}
	}
	return 0;
}
