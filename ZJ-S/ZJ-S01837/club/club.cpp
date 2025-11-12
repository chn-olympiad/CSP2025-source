#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
typedef long long ll;
ll ans;
int t,n;
struct node{
	int a,b;
}stu[maxn][4];


bool cmp(node c,node d){
	return c.a>d.a;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		priority_queue< pair<int,int> >x[4];
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&stu[i][j].a);
				stu[i][j].b=j;
			}
			sort(stu[i]+1,stu[i]+4,cmp);
			if(x[stu[i][1].b].size()>=n/2) //第一志愿填满了 
			{
				int k=x[stu[i][1].b].top().second;
				//int satisfy=-(x[stu[i][1].b].top().first);
				if(stu[i][1].a+stu[k][2].a>stu[i][2].a+stu[k][1].a)
				{
					ans-=stu[k][1].a;
					x[stu[i][1].b].pop();
					ans+=stu[i][1].a;
					x[stu[i][1].b].push(make_pair(stu[i][2].a-stu[i][1].a,i));
					ans+=stu[k][2].a;
					x[stu[k][2].b].push(make_pair(stu[k][2].a-stu[k][1].a,k));
				}
				else //填第二志愿 
				{
					ans+=stu[i][2].a;
					x[stu[i][2].b].push(make_pair(-stu[i][2].a,i));
				}
			}
			else
			{
				ans+=stu[i][1].a;
				x[stu[i][1].b].push(make_pair(stu[i][2].a-stu[i][1].a,i));
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
