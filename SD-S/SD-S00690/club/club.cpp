#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c;
};
node n1[100000];
vector<int> num1;
int s[10000],numx=0,n,x=0;
void bfs(int o,int num,int nx,int n2,int n3)
{
	if(o==n) 
	{
		num1.push_back(num);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1)
		{
			if(nx==n/2) continue;
		}
		if(i==2)
		{
			if(n2==n/2) continue;
		}
		if(i==3)
		{
			if(n3==n/2) continue;
		}
		if(i==1&&nx<n/2)
		{
			bfs(o+1,num+n1[o].a,nx+1,n2,n3);
		}
		else if(i==2&&n2<n/2)
		{
			bfs(o+1,num+n1[o].b,nx,n2+1,n3);
		}
		else if(i==3&&n3<n/2)
		{
			bfs(o+1,num+n1[o].c,nx,n2,n3+1);
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<1000;i++)
		{
			n1[i].a = 0;
			n1[i].b = 0;
			n1[i].c = 0;
	 	}
		for(int i=0;i<n;i++)
		{
			cin>>n1[i].a>>n1[i].b>>n1[i].c;
	 	}
	 	bfs(0,0,0,0,0);
		for(int i=x;i<num1.size();i++)
		{
			numx = max(numx,num1[i]); 
		}
		cout<<numx;
		x=num1.size()+1;
	}
	return 0;
}
