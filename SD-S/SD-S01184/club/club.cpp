#include <bits/stdc++.h>
using namespace std;
int n,T;
struct node
{
	int a1,a2,a3;
}a[100005];
struct cc
{
	int num,c,xx;
}t[100005];
int c[100005],d[100005],e[100005];
long long pos1,pos2,pos3,ans;
bool f1[100005],f2[100005],f3[100005];

bool cmp(cc x,cc y)
{
	return x.c >= y.c;	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n;
		pos1 = 0,pos2 = 0,pos3 = 0,ans = 0;
		memset(t,0,sizeof t);
		memset(a,0,sizeof a);
		memset(c,0,sizeof c);
		memset(d,0,sizeof d);
		memset(e,0,sizeof e);
		memset(f1,0,sizeof f1);
		memset(f2,0,sizeof f2);
		memset(f3,0,sizeof f3);
		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if (a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3)
				c[++pos1] = i;
			else if (a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3)
				d[++pos2] = i;
			else
				e[++pos3] = i;			
		}
		if (pos1 > n/2)
		{
			for (int i = 1; i <= pos1; i ++)
			{
				t[i].num = c[i];
				if (a[c[i]].a2 >= a[c[i]].a3)
				{
					t[i].c = a[c[i]].a1 - a[c[i]].a2,t[i].xx = 2;
				}			
				else
				{
					t[i].c = a[c[i]].a1 - a[c[i]].a3,t[i].xx = 3;	
				}
			}
			sort(t+1,t+pos1+1,cmp);
			for (int i = pos1;i > n/2; i--)
			{
				if (t[i].xx == 2) 
					d[++pos2] = t[i].num;
				else
					e[++pos3] = t[i].num;
				f1[t[i].num] = true;
			}				
		}
		else if (pos2 > n/2)
		{
			for (int i = 1; i <= pos2; i ++)
			{
				t[i].num = d[i];
				if (a[d[i]].a1 >= a[d[i]].a3)
				{
					t[i].c = a[d[i]].a2 - a[d[i]].a1,t[i].xx = 1;
				}			
				else
				{
					t[i].c = a[d[i]].a2 - a[d[i]].a3,t[i].xx = 3;	
				}
			}
			sort(t+1,t+pos2+1,cmp);
			for (int i = pos2;i > n/2; i--)
			{
				if (t[i].xx == 1) 
					c[++pos1] = t[i].num;
				else
					e[++pos3] = t[i].num;
				f2[t[i].num] = true;
			}		
		}
		else
		{
			for (int i = 1; i <= pos3; i ++)
			{
				t[i].num = e[i];
				if (a[e[i]].a1 >= a[e[i]].a2)
				{
					t[i].c = a[e[i]].a3 - a[e[i]].a1,t[i].xx = 1;
				}			
				else
				{
					t[i].c = a[e[i]].a3 - a[e[i]].a2,t[i].xx = 2;	
				}
			}
			sort(t+1,t+pos3+1,cmp);
			for (int i = pos3;i > n/2; i--)
			{
				if (t[i].xx == 1) 
					c[++pos1] = t[i].num;
				else
					d[++pos2] = t[i].num;
				f3[t[i].num] = true;
			}			
		}
		
		
		
		for (int i = 1; i <= pos1; i ++) 
		{
			if (!f1[c[i]])
			{
				ans += a[c[i]].a1;
			}	
		}
		for (int i = 1; i <= pos2; i ++) 
		{
			if (!f2[d[i]])
			{
				ans += a[d[i]].a2;
			}
		}
		for (int i = 1; i <= pos3; i ++) 
		{
			if (!f3[e[i]])
			{
				ans += a[e[i]].a3;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
