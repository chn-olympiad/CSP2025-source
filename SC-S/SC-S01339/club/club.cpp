/*
终于想出来了
这是一个贪心问题
每一次只可能有一个部门“溢出” 
然后就比较显然的贪心了 
exp:100pts 
*/
#include<bits/stdc++.h>
using namespace std;
int T;
int n;
const int N=100010;
struct node
{
	int val,id;
	bool operator<(const node &x)const
	{
		return x.val<val;
	}
};
bool in1[N],in2[N],in3[N];
priority_queue<node>que[3];
int sum1,sum2,sum3;
void solve()
{
	while(!que[0].empty())que[0].pop();
	while(!que[1].empty())que[1].pop();
	while(!que[2].empty())que[2].pop();
	memset(in1,0,sizeof in1);
	memset(in2,0,sizeof in2);
	memset(in3,0,sizeof in3);
	sum1=sum2=sum3=0;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(x>=y&&x>=z)
		{
			que[0].push({min(x-y,x-z),i});
			in1[i]=1;
			sum1++;
			ans+=x;
			while(sum1>n/2)
			{
				if(in1[que[0].top().id]==0)
				{
					que[0].pop();
				}
				else
				{
					in1[que[0].top().id]=0;
					sum1--;
					ans-=que[0].top().val;
					que[0].pop();
				}
			}
			continue;
		}
		if(y>=x&&y>=z)
		{
			que[1].push({min(y-x,y-z),i});
			in2[i]=1;
			sum2++;
			ans+=y;
			while(sum2>n/2)
			{
				if(in2[que[1].top().id]==0)
				{
					que[1].pop();
				}
				else
				{
					in2[que[1].top().id]=0;
					sum2--;
					ans-=que[1].top().val;
					que[1].pop();
				}
			}
			continue;
		}
		if(z>=x&&z>=y)
		{
			que[2].push({min(z-y,z-x),i});
			in3[i]=1;
			sum3++;
			ans+=z;
			while(sum3>n/2)
			{
				if(in3[que[2].top().id]==0)
				{
					que[2].pop();
				}
				else
				{
					in3[que[2].top().id]=0;
					sum3--;
					ans-=que[2].top().val;
					que[2].pop();
				}
			}
			continue;
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
/*
1
4
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722

1
2
2020 14533 18961
2423 15344 16322
*/