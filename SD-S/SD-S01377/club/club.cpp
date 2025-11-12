#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int t,n;
struct node{
	int a,b,c;
}cl[100005];
int bj[100005];
int p[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int k=(n>>1);
		int sa,sb,sc;
		sa=sb=sc=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&cl[i].a,&cl[i].b,&cl[i].c);
			if(cl[i].a>=max(cl[i].b,cl[i].c))
			{
				cnt+=cl[i].a;
				sa++;
				bj[i]=1;
			}
			else if(cl[i].b>=max(cl[i].a,cl[i].c))
			{
				cnt+=cl[i].b;
				sb++;
				bj[i]=2;
			}
			else
			{
				cnt+=cl[i].c;
				sc++;
				bj[i]=3;
			}
		}
		if(sa<=k&&sb<=k&&sc<=k)
		{
			cout<<cnt<<"\n";
			continue;
		}
		if(sa>k)
		{
			priority_queue<int>q;
			int nd=sa-k;
			for(int i=1;i<=n;i++)
				if(bj[i]==1)
					q.push(max(cl[i].b,cl[i].c)-cl[i].a);
			for(int i=1;i<=nd;i++)
			{
				cnt+=q.top();
				q.pop();
			}
			cout<<cnt<<"\n";
		}
		else if(sb>k)
		{
//			cout<<222<<"\n";
			
			priority_queue<int>q;
			int nd=sb-k;
			for(int i=1;i<=n;i++)
				if(bj[i]==2)
					q.push(-cl[i].b+max(cl[i].a,cl[i].c));
			while(nd--)
			{
				cnt+=q.top();
				q.pop();
			}
			cout<<cnt<<"\n";
		}
		else
		{
//			cout<<333<<"\n";
			
			priority_queue<int>q;
			int nd=sc-k;
			for(int i=1;i<=n;i++)
				if(bj[i]==3)
					q.push(-cl[i].c+max(cl[i].b,cl[i].a));
			while(nd--)
			{
				cnt+=q.top();
				q.pop();
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
	//Thanks
}
