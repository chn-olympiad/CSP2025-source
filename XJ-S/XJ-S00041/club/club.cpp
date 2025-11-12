#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
long long ans=0;//最大得分 
struct xs
{
	int cj[3];//加的分 
	int djg[3];//原来是哪个部门的 
}arr[N];

bool cmp(xs x,xs y)
{
	if(x.cj[0]==y.cj[0])
	{
		if(x.cj[1]==y.cj[1])
		{
			return x.cj[2]>=y.cj[2];
		}
		else
			return x.cj[1]>=y.cj[1];
	}
	else
		return x.cj[0]>=y.cj[0];
}

void dfs(int wz,int gs[3],long long int cnt)
{
	if(wz>n)
	{
		ans=max(ans,cnt);
		return ;
	}
	for(int a=0;a<3;a++)
	{
		int x=arr[wz].cj[a];
		int y=arr[wz].djg[a];
		if(gs[y]+1<=n/2)
		{
			cnt+=x;
			gs[y]++;
			dfs(wz+1,gs,cnt);
			cnt-=x;
			gs[y]--;
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(int a=1;a<=n;a++)
		{
			scanf("%d%d%d",&arr[a].cj[0],&arr[a].cj[1],&arr[a].cj[2]);//输入 
			int cj1=arr[a].cj[0];
			int cj2=arr[a].cj[1];
			int cj3=arr[a].cj[2];//挨个保存 
			arr[a].djg[0]=1;
			arr[a].djg[1]=2;
			arr[a].djg[2]=3;
			//排序
			for(int i=0;i<3;i++)
			{
				for(int j=i+1;j<3;j++)
				{
					if(arr[a].cj[i]<arr[a].cj[j])
					{
						swap(arr[a].djg[i],arr[a].djg[j]);
						swap(arr[a].cj[i],arr[a].cj[j]);
					}
				}
			}
		}
		sort(arr+1,arr+n+1,cmp);
		int gs[3]={0,0,0};//每个部门的人数
		dfs(0,gs,0LL);
		printf("%d\n",ans);
	}
	return 0;
} 
