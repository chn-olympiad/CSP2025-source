//高铭泽  SN-S00799  渭南高级中学 
#include<bits/stdc++.h>
using namespace std;
int n,j[100001][4],i,aaa = 0,b;
int jj[100001];
int t;
void px(int q)
{
	for(int x = 1;x<=n;x++)
	{
		for(int y = x;y<=n;y++)
		{
			if(j[x][q]<j[y][q])
			{
				swap(j[x][1],j[y][1]);
				swap(j[x][2],j[y][2]);
				swap(j[x][3],j[y][3]);
				swap(jj[x],jj[y]);
			}
		}
	}
	return ;
}
int club()
{
	int s;
	cin>>n;
	for(int q = 1;q<=n;q++)
	{
		cin>>j[q][1]>>j[q][2]>>j[q][3];
	}
	for(int q = 1;q<=3;q++)
	{
		px(q);
		if(q == 1)
		{
			for(s = 1;s<=n && i<n/2;s++)
			{
				if(j[s][1]>=j[s][2] && j[s][1]>=j[s][3] && jj[s]!=0)
				{
					jj[s] = 0;
					aaa+=j[s][1];
					i++;
				}
			}
			i = 0;
		}
		if(q == 2)
		{
			for(s = 1;s<=n && i<n/2;s++)
			{
				if(j[s][2]>=j[s][3] && jj[s]!=0)
				{
					jj[s] = 0;
					aaa+=j[s][2];
					i++;
				}
			}
			i = 0;
		}
		if(q == 3)
		{
			for(s = 1;s<=n && i<n/2;s++)
			{
				if(jj[s]!=0)
				{
					jj[s] = 0;
					aaa+=j[s][3];
					i++;
				}
			}
			i = 0;
		}
	}
	return aaa;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q = 1;q<=t;q++)
	{
		for(int q = 0;q<=100000;q++)jj[q] = q;
		aaa = 0;
		n = 0;
		cout<<club()<<endl;
	}
	return 0;
}
