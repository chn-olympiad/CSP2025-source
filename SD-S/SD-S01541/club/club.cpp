#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct node{
	int x,y,z,ch,lei;
};
bool cmp(node q,node p)
{
	return q.ch<p.ch;
}
node a[N];
void solve()
{
	int n,cnt=0;
	int ap=0,bp=0,cp=0;
	cin>>n;

	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].x>=max(a[i].y,a[i].z))
		{
			ap++;
			a[i].ch=a[i].x-max(a[i].y,a[i].z); 
			a[i].lei=1;
			cnt+=a[i].x;
		}
		else if(a[i].y>=max(a[i].x,a[i].z))
		{
			bp++;
			a[i].ch=a[i].y-max(a[i].x,a[i].z);
			a[i].lei=2;
			cnt+=a[i].y;
		}
		else
		{
			cp++;
			a[i].ch=a[i].z-max(a[i].x,a[i].y);
			a[i].lei=3;
			cnt+=a[i].z;
		}
	}
	sort(a+1,a+n+1,cmp);
	int op=-1,dai=-1;
	if(ap>n/2) op=1,dai=ap-n/2;
	else if(bp>n/2) op=2,dai=bp-n/2;
	else if(cp>n/2) op=3,dai=cp-n/2;
	else
	{
		cout<<cnt<<'\n';
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!dai) break;
		if(a[i].lei==op)
		{
			cnt-=a[i].ch;
			dai--; 
		}
	}
	cout<<cnt<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	} 
	return 0;
}

