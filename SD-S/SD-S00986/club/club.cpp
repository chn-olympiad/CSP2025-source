#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include<vector>
#include<queue>
#define PII pair<int,int>
using namespace std;
struct node
{
	int c1,c2,c3;
}a[100007];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		vector<int>v[4];
		priority_queue<PII,vector<PII>,greater<PII> >q;
		int n;
		long long ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int b1,b2,b3;
			scanf("%d%d%d",&b1,&b2,&b3);
			a[i].c1=b1;
			a[i].c2=b2;
			a[i].c3=b3;
			if(b1>=b2&&b1>=b3) 
			{
				v[1].push_back(i);
				ans+=b1;
			}
			else if(b2>=b1&&b2>=b3)
			{
				v[2].push_back(i);
				ans+=b2;
			}
			else if(b3>=b1&&b3>=b2)
			{
//				cout<<"*"<<endl;
				v[3].push_back(i);
//				cout<<"*"<<endl;
				ans+=b3;
			}
		}
		int si1=v[1].size();
		int si2=v[2].size();
		int si3=v[3].size();
		if(si1>n/2)
		{
			for(int i=0;i<v[1].size();i++)
			{
				int cha=a[v[1][i]].c1-max(a[v[1][i]].c2,a[v[1][i]].c3);
				PII p;p.first=cha;p.second=v[1][i];
				q.push(p);
			}
			while(si1>n/2)
			{
				PII p=q.top();
				q.pop();
				ans-=p.first;
				si1--;
			}
		}
		if(si2>n/2)
		{
			for(int i=0;i<v[2].size();i++)
			{
				int cha=a[v[2][i]].c2-max(a[v[2][i]].c1,a[v[2][i]].c3);
				PII p;p.first=cha;p.second=v[2][i];
				q.push(p);
			}
			while(si2>n/2)
			{
				PII p=q.top();
				q.pop();
				ans-=p.first;
				si2--;
			}
		}
		if(si3>n/2)
		{
			for(int i=0;i<v[3].size();i++)
			{
				int cha=a[v[3][i]].c3-max(a[v[3][i]].c2,a[v[3][i]].c1);
				PII p;p.first=cha;p.second=v[3][i];
				q.push(p);
			}
			while(si3>n/2)
			{
				PII p=q.top();
				q.pop();
				ans-=p.first;
				si3--;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
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
