#include<iostream> 
#include<cmath>
using namespace std;
int n=0,maxm=0;
int S_V[100010][3];
int dfs(int dpth,int BMS[],int cnt)
{
	int maxmm=-114514;
	if(dpth<n)
	{
		for(int i=0;i<3;i++)
		{
			if(BMS[i]<n/2)
			{
			BMS[i]++;
			maxmm=max(maxmm,dfs(dpth+1,BMS,cnt+S_V[dpth][i]));
			BMS[i]--;
			}
		}
		return maxmm; 
	}
	else
	{
		return cnt;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int f=0;
	cin>>f;
	for(int l=0;l<f;l++)
	{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>S_V[i][j];
		}
	}
	int BMS_[3]={0,0,0};
	cout<<dfs(0,BMS_,0)<<endl;
	}
	return 0;
}
