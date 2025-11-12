//SN-S00824 龚西贝 西安建筑科技大学附属中学 
#include<bits/stdc++.h>
using namespace std;
struct logan
{
	int a[3]={};
	int maax_n,mid_n,miin_n;
	int cnm;
};
void lo(logan &x)
{
//  a0
	if(x.a[0]==max(x.a[0],max(x.a[1],x.a[2])))
	{
		x.maax_n=0;
	} 
	else if(x.a[0]==min(x.a[0],min(x.a[1],x.a[2])))
	{
		x.miin_n=0;
	}
	else
	{
		x.mid_n=0;
	}
//  a1
	if(x.a[1]==max(x.a[0],max(x.a[1],x.a[2])))
	{
		x.maax_n=1;	
	} 
	else if(x.a[1]==min(x.a[0],min(x.a[1],x.a[2])))
	{
		x.miin_n=1;
	}
	else
	{
		x.mid_n=1;
	}
//  a2	
	if(x.a[2]==max(x.a[0],max(x.a[1],x.a[2])))
	{
		x.maax_n=2;	
	} 
	else if(x.a[2]==min(x.a[0],min(x.a[1],x.a[2])))
	{
		x.miin_n=2;
	}
	else
	{
		x.mid_n=2;
	}
//  cnm
	x.cnm=x.a[x.maax_n]-x.a[x.mid_n]-x.a[x.miin_n];
}
bool xy(logan x,logan y)
{
	return x.cnm>y.cnm;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int answer[10]={};
	for(int c=0;c<t;c++)
	{
		int cnt[3]={};
		vector<logan> q;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			logan xx;
			cin>>xx.a[0]>>xx.a[1]>>xx.a[2];
			lo(xx);
			q.push_back(xx);
		}
		sort(q.begin(),q.end(),xy);
		for(int i=0;i<n;i++)
		{
			if(cnt[q[i].maax_n]<=n/2)
			{
				cnt[q[i].maax_n]++;
				answer[c]+=q[i].a[q[i].maax_n];
			}
			else if(cnt[q[i].mid_n]<=n/2)
			{
				cnt[q[i].mid_n]++;
				answer[c]+=q[i].a[q[i].mid_n];
			}
			else
			{
				cnt[q[i].miin_n]++;
				answer[c]+=q[i].a[q[i].miin_n];
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<answer[i]<<endl;
	}
	return 0;
}
