#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ansa,ansb,ansc,pa,pb,pc,ans;/*a[500005],b[500005],c[500005]*/
//a[i]:i qudi yi gebumendemanyidu
struct node
{
	int a,b,c;
}peo[500005];
int ca[100005],cb[100005],cc[100005];
int dd(node ku,int k)
{
	if (k == 1) return max(max(ku.a,ku.b),ku.c);
	if (k == 2)
	{
		if (ku.a >= ku.b && ku.b >= ku.c) return ku.b;
		if (ku.c >= ku.b && ku.b >= ku.a) return ku.b;
		if (ku.b >= ku.a && ku.a >= ku.c) return ku.a;
		if (ku.c >= ku.a && ku.a >= ku.b) return ku.a;
		if (ku.a >= ku.c && ku.c >= ku.b) return ku.c;
		if (ku.b >= ku.c && ku.c >= ku.a) return ku.c;
	}
	if (k == 3) return min(ku.a,min(ku.b,ku.c));
}
bool cmp(node x,node y)
{
	if (dd(x,1) != dd(y,1))
	{
		return dd(x,1)>dd(y,1);
	}
	else if (dd(x,2) != dd(y,2))
	{
		return dd(x,2)>dd(y,2);
	}
	else return dd(x,3)>dd(y,3);
}
signed main()
{
	freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		pa = 0;
		pb = 0;
		pc = 0;
		ansa = 0;
		ansb = 0;
		ansc = 0;
		ans = 0;
		cin>>n;
		for (int i = 1;i <= n;i++)
		{
			cin>>peo[i].a>>peo[i].b>>peo[i].c;
		}
		sort(peo+1,peo+n+1,cmp);
		for (int i = 1;i <= n;i++)
		{
			/*if (dd(peo[i],1) == dd(peo[i],2) && dd(peo,3) == dd(peo,2))
			{
				if (min(pa,min(pb,pc)) == pa)
				{
					ca[++pa] = i;
					ansa+=peo[i].a;
				}
				else if (min(pa,min(pb,pc)) == pb)
				{
					cb[++pb] = i;
					ansb+=peo[i].b;
				}
				else 
				{
					cc[++pc] = i;
					ansc+=peo[i].c;
				}
			}
			else if (dd(peo[i],1) == dd(peo[i],2))
			{
				
			}
			else 
			{
				
			}*/
			if (dd(peo[i],1) == peo[i].a)
			{
				ca[++pa] = i;
				ansa+=peo[i].a;
			}
			else if (dd(peo[i],1) == peo[i].b)
			{
				cb[++pb] = i;
				ansb+=peo[i].b;
			}
			else
			{
				cc[++pc] = i;
				ansc+=peo[i].c;
			}
		}
		ans = ansa+ansb+ansc;
		if (pa > n/2)
		{
			for (int i = 1;i <= pa;i++)
			{
				ca[i] = dd(peo[i],2)-dd(peo[i],1);
			}
			sort(ca+1,ca+pa+1);
			for (int i = n/2+1;i <= pa;i++)
			{
				ans+=ca[i];
			}
		}
		else if (pb > n/2)
		{
			for (int i = 1;i <= pb;i++)
			{
				cb[i] = dd(peo[i],2)-dd(peo[i],1);
			}
			sort(cb+1,cb+pb+1);
			for (int i = n/2+1;i <= pb;i++)
			{
				ans+=cb[i];
			}
		}
		else if (pc > n/2)
		{
			for (int i = 1;i <= pc;i++)
			{
				cc[i] = dd(peo[i],2)-dd(peo[i],1);
			}
			sort(cc+1,cc+pc+1);
			for (int i = n/2+1;i <= pc;i++)
			{
				ans+=cc[i];
			}
		}
		cout << ans << endl;
	}
}
