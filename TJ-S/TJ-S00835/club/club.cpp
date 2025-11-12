#include <bits/stdc++.h> 
using namespace std;

struct now
{
	int id;
	int x1;
	int x2;
	int x3;
}a[100005]; 
struct node
{
	int id1;
	int id2;
	int x;
};

bool cmp1(now a1,now b1)
{
    if(a1.x1 > b1.x1) return a1.x1 > b1.x1 ;
    else return a1.id > b1.id;
}
bool cmp2(now a2,now b2)
{
    if(a2.x2 > b2.x2) return a2.x2 > b2.x2 ;
    else return a2.id > b2.id;
}
bool cmp3(now a3,now b3)
{
    if(a3.x3 > b3.x3) return a3.x3 > b3.x3 ;
    else return a3.id > b3.id;
}
bool cmp4(node a4,node b4)
{
    if(a4.x > b4.x) return a4.x > b4.x ;
    else return a4.id2 > b4.id2;
}

vector<bool> dis(100005,false);
node maxn[4];
int cnt[4] = {0,0,0,0};
int main()
{
	int t,n = 0;
	cin >> t;
	for(int k = 1;k <= t;k++)
	{
		int qw = 0;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i].x1 >> a[i].x2 >> a[i].x3;
			a[i].id =i;
		}
		for(int i = 1;i <= n;i++)
		{
            sort(a+1,a+n+1,cmp1);
            maxn[1].id1 = 1;
            maxn[1].id2 = a[n].id;
            maxn[1].x = a[n].x1;
            sort(a+1,a+n+1,cmp2);
            maxn[2].id1 = 2;
            maxn[2].id2 = a[n].id;
            maxn[2].x = a[n].x2;
            sort(a+1,a+n+1,cmp3);
            maxn[3].id1 = 3;
            maxn[3].id2 = a[n].id;
            maxn[3].x = a[n].x3;
            sort(maxn+1,maxn+4,cmp4);
            if(dis[maxn[3].id2] == false && 2*cnt[maxn[3].id1] < n)
			{
				cnt[maxn[3].id1]++;
				qw = qw + maxn[3].x;
				dis[maxn[3].id2] = true;
				a[maxn[3].id2].x1 = 0;
				a[maxn[3].id2].x2 = 0;
				a[maxn[3].id2].x3 = 0;
			}
            else if(dis[maxn[2].id2] == false && 2*cnt[maxn[2].id1] < n)
			{
				cnt[maxn[2].id1]++;
				qw = qw + maxn[2].x;
				dis[maxn[2].id2] = true;
				a[maxn[2].id2].x1 = 0;
				a[maxn[2].id2].x2 = 0;
				a[maxn[2].id2].x3 = 0;
		    }
			else
			{
				cnt[maxn[1].id1]++;
				qw = qw + maxn[1].x;
				dis[maxn[1].id2] = true;
				a[maxn[1].id2].x1 = 0;
				a[maxn[1].id2].x2 = 0;
				a[maxn[1].id2].x3 = 0;
			}
         
		}
		cout << qw << endl;
	}
	return 0;
}
