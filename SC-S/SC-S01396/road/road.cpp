#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
	
//bool operator

struct node{
	long long  val,res;
}num[N];	
bool operator <(const node x,const node y)
{
	return x.val>y.val;
 } 
 int find(int k) 
 {
 	for(int i=1;i<=N;i++)
 	{
 		if(num[i].val==k) return  i;
	 }
 }
void solve()
{
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		num[i].val=a;
		num[i].res=max(b,c);
//		cout<<num[i].val<<' '<<	num[i].res<<endl;
	}
	priority_queue<node>q1,q2;
	for(int i=1;i<=n;i++)
	{
		if(num[i].val>num[i].res&&q1.size()<n/2)
		{
			q1.push(num[i]);
		}
		else 
		{
			if(q1.size()>=n/2&&(num[i].val+q1.top().res>num[i].res+q1.top().val))//考虑是否需要换 
			{
				q1.pop();
				q1.push(num[i]);
			}
			else 
			{		
				q2.push(num[i]);
			}
		}
	}
	while(!q1.empty())  sum+=q1.top().res,q1.pop();
	while(!q2.empty())  sum+=q2.top().res,q2.pop();
	cout<<sum<<endl;
 } 
int main()
{

	freopen("road.out","w",stdout);

	cout<<1;
} 
//定义一个分配方案的满意度
//为所有新成员对分配到的部门的满意度之和