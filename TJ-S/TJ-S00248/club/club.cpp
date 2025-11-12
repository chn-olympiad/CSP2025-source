#include<bits/stdc++.h>
using namespace std;
long long t,n,f,max_join,has_num[4],sum,nmax;
struct node
{
	int p1;
	int p2;
	int p3;
	bool yc;
}a[200009];
struct max_node
{
	int data;
	int xh;
	int cho;
}maxl[600090];
bool cmp(max_node x,max_node y)
{
	return x.data>y.data;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		//初始化部分 
		memset(a,0,sizeof(a));
		memset(maxl,0,sizeof(maxl));
		memset(has_num,0,sizeof(has_num));
		n=0;f=0;max_join=0;sum=0;
		
		cin>>n;
		max_join=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].p1>>a[i].p2>>a[i].p3;
			//最大期望值 
			f++;
			maxl[f].data=a[i].p1;
			maxl[f].cho=1;
			maxl[f].xh=i;
			f++;
			maxl[f].data=a[i].p2;
			maxl[f].cho=2;
			maxl[f].xh=i;
			f++;
			maxl[f].data=a[i].p3;
			maxl[f].cho=3;
			maxl[f].xh=i;
		}
		sort(maxl+1,maxl+1+f,cmp);
		for(int i=1;i<=n*3;i++)
		{
			//cout<<"第"<<i<<"大的值是第"<<maxl[i].xh<<"人选择的"<<maxl[i].cho<<"号部门，他的值是"<<maxl[i].data<<endl;
			if(a[maxl[i].xh].yc==1) continue;//这个人已经选过了 
			if(has_num[maxl[i].cho]>=max_join) continue;//这个部门已经满了
			a[maxl[i].xh].yc=1;
			has_num[maxl[i].cho]++;
			sum+=maxl[i].data;
		}
		cout<<sum<<endl;
	}
	return 0;
}
