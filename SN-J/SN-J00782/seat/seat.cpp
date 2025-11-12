//考号:SN-J00782  姓名:王浩轩  学校:西安滨河学校
#include<bits/stdc++.h>
#define int  long long
using namespace std;
int t[1005],s[15][15];
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,c,r;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++)
	{
		cin>>t[i];
	}
	int tt=t[1];
	sort(t+1,t+n+1);
	int h=1,l=1;
	for(int i=n*m;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			h++;
		}
		l++;
		s[h][l]=t[i];
		for(int j=1;j<=n;j++)
		{
			h--;
		}
		l++;
		s[h][l]=t[i];
	}
	for(int i=1;i<=h;i++)
	{
		for(int i=1;i<=l;i++)
		{
			if(s[h][l])
			{
				if(s[h][l]==tt)
				{
					cout<<l<<h;
				}
			}
		}
	}
    return 0;
}

