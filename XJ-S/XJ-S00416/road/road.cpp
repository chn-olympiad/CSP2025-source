#include <bits/stdc++.h>

using namespace std;
int n,m,k;
int lj[10020][10020][2];//邻接 
int c[10][10010];//乡村 
int f[10010];//最小权值判断用
int ff[20];//选择乡村判断用 
long long mi,miiiiiiiiii;


void dfschengzhen(int,int);
void zuixiaoquanzhi(int);
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++)
	{
		int aaa,bbb,ccc;
		cin>>aaa>>bbb>>ccc;
		lj[aaa][bbb][0] = 1;
		lj[aaa][bbb][1] = ccc;
		lj[bbb][aaa][0] = 1;
		lj[bbb][aaa][1] = ccc;
	}
	for(int i = 1;i<=k;i++)
	{
		cin>>c[i][0];
		for(int j = 1;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	
	for(int abcdefg = 0;abcdefg<k;abcdefg++)
	{
		dfschengzhen(0,abcdefg);
	}
	
	cout<<miiiiiiiiii;
	return 0;
}
void dfschengzhen(int p,int pppppppppp)
{
	if(p==pppppppppp) zuixiaoquanzhi(pppppppppp);
	for(int i = p+1;i<=k;i++)
	{
		if(ff[i]==0)
		{
			ff[i] = 1;
			dfschengzhen(i,pppppppppp);
			ff[i] = 0;
		}
	}
}
void zuxiaoquanzhi(int abcdefg)
{
	mi = 0;
	for(int i = 1;i<=k;i++)
	{
		if(f[i]==1) mi += c[i][0];
	}
	int p = 1;
	f[1] = 1;
	for(int i = 1;i<=n+k;i++)
	{
		for(int j = 1;j<=n+k;j++)
		{
			if(i>n&&f[i]==1)
			{
				lj[i][j][0] = 1;
				lj[i][j][1] = c[i-n][j];
			}
			if(j>n&&f[j]==1)
			{
				lj[j][i][0] = 1;
				lj[j][i][1] = c[i-n][j];
			}
		}
	}
	while(true)
	{
		bool ffffffffffffffffffff = true;
		for(int i = 1;i<=n;i++)
		{
			if(f[i]==0)
			{
				ffffffffffffffffffff = false;
				break;
			}
		}
		if(ffffffffffffffffffff==true)
		{
			break;
		}
		int benlunmubiao = -1;
		for(int i = 1;i<=n+abcdefg;i++)
		{
			if(lj[i][p][0]==1&&f[i]==0)
			{
				benlunmubiao = i;
				break;
			}
		}
		int mii = 999999999;
		for(int i = 1;i<=n+abcdefg;i++)
		{
			if(lj[benlunmubiao][i][0]==1&&f[i]==1&&lj[benlunmubiao][i][1]<mii)
			{
				mii = lj[benlunmubiao][i][1];
			}
		}
		mi += mii;
		f[benlunmubiao] = 1;
		p = benlunmubiao; 
//		cout<<mi<<" "<<p<<endl;
//		for(int i = 1;i<=n;i++)
//		{
//			cout<<f[i]<<" ";
//		}
//		system("pause");
	}
	miiiiiiiiii = min(mi,miiiiiiiiii);
}
