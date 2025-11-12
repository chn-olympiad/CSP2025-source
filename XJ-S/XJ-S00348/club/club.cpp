#include<bits/stdc++.h>
using namespace std;
int t,ans,sum,n;
struct node
{
	int x;
	int y;
	int z;
}a[200005];
void fun(int id,int a1,int a2,int a3)
{
	if(id > n)
	{
		sum = max(sum , ans);
		return ;
	}
	else
	{
		for(int i = 1; i <= 3; i++)
		{
			int flag = 0;
			if(i == 1 && a1 < n / 2){
				a1++;
				ans += a[id].x;
				flag = 1;
			}	
			if(i == 2 && a2 < n / 2){
				a2++;
				ans += a[id].y;
				flag = 2;
			}	
			if(i == 3 && a3 < n / 2){
				a3++;
				ans += a[id].z;
				flag = 3;
			}
			if(flag == 0)
				continue;
			fun(id + 1,a1,a2,a3);
			if(flag == 1)
				a1--, ans -= a[id].x;
			if(flag == 2)
				a2--, ans -= a[id].y;
			if(flag == 3)
				a3--, ans -= a[id].z;
		}
	}
}
bool cmp(node q,node p)
{
	return q.x>p.x;
}
bool cmp1(node q,node p)
{
	if(q.x > q.y)
		return q.x > p.y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t --)
	{
		cin>>n;
		for(int i = 1; i <= n; i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n > 30)
		{
			bool flag = true;
			for(int i = 1; i <= n; i++)
				if(a[i].y != 0)
				{
					flag = false;
					break;
				}
			if(flag == true)
			{
				sort(a + 1, a + 1 + n, cmp1);
				for(int i = 1; i <= n / 2; i++)
					sum += a[i].x;
				for(int i = n / 2 + 1; i <= n; i++)
					sum += a[i].y;
			}
			else
			{
				sort(a + 1, a + 1 + n, cmp);
				
				for(int i = 1; i <= n / 2; i++)
					sum += a[i].x;
			}
		}
		else
		fun(1,0,0,0);
		cout<<sum;
		sum = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
