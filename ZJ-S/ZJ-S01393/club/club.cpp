#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int sign1[N*4],sign2[N*4];
struct node1{
	int t1,t2,t3,A,B,C;
}a[N];
struct node{
	int number,id;
	ll style,ansk;
}b[N*4];
bool cmp(node x,node y)
{
	return x.number>y.number;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		ll ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(sign1,0,sizeof(sign1));
		memset(sign2,0,sizeof(sign2));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].A>>a[i].B>>a[i].C;
			a[i].t1=min(a[i].A-a[i].B,a[i].A-a[i].C);
			a[i].t2=min(a[i].B-a[i].A,a[i].B-a[i].C);
			a[i].t3=min(a[i].C-a[i].A,a[i].C-a[i].B);
			b[i*3-2].number=a[i].t1;b[i*3-1].number=a[i].t2;b[i*3].number=a[i].t3;
			b[i*3-2].ansk=a[i].A;b[i*3-1].ansk=a[i].B;b[i*3].ansk=a[i].C;
			b[i*3-2].id=i;b[i*3-1].id=i;b[i*3].id=i;//编号 
			b[i*3-2].style=1;b[i*3-1].style=2;b[i*3].style=3;//类型 
		}
		sort(b+1,b+3*n+1,cmp);
		int maxn=n/2;//sign1记录编号 sign2记录类型 
		for(int i=1;i<=n*3;i++)
		{
			if(!sign1[b[i].id]&&sign2[b[i].style]<maxn)
			{
				sign1[b[i].id]=1;
				sign2[b[i].style]++;
				ans+=b[i].ansk;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<a[i].t1<<" "<<a[i].t2<<" "<<a[i].t3<<"\n";
//		}
		cout<<ans<<"\n";
	}
	return 0;
}
