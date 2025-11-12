#include<bits/stdc++.h>
using namespace std;
int srh[110000];
int srh2[110000][3];
int test,a;
long long dfs(long long all,int cl1,int cl2,int cl3,int non)
{
	bool can[3];
	can[0]=(cl1<a/2);
	can[1]=(cl2<a/2);
	can[2]=(cl3<a/2);
	long long best=0;
	for(int I=0;I<a;I++)
	{
		if(can[I])
		{
			if(I==0) cl1++,all+=srh2[non][0];
			else if(I==1) cl2++,all+=srh2[non][1];
			else cl3++,all+=srh2[non][2];
			if(non==a-1) best=max(best,all);
			else best=max(best,dfs(all,cl1,cl2,cl3,non+1));
			if(I==0) cl1--,all-=srh2[non][0];
			else if(I==1) cl2--,all-=srh2[non][1];
			else cl3--,all-=srh2[non][2];
		}
	}
	return best;
}
void solve1()
{
	int num;
	cout<<dfs(0,0,0,0,0)<<endl;
}
void solve2()
{
	for(int I=0;I<a;I++)
	{
		int x;
		for(int J=0;J<3;J++)
		{
			cin>>srh[I]>>x>>x;
		}
	}
	sort(srh,srh+a,greater<int>());
	long long ans=0;
	for(int I=0;I<a/2;I++)
	{
		ans+=srh[I];
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>test;
	for(int T=0;T<test;T++)
	{
		cin>>a;
		if(a<=31)
		{
			for(int I=0;I<a;I++)
			{
				for(int J=0;J<3;J++)
				{
					cin>>srh2[I][J];
				}
			}
			solve1();
		}
		else solve2();
	}
	
	return 0;
}
