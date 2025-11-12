#include<bits/stdc++.h>
using namespace std;
long long q1,q2,q3,vis[200010],nt1,nt2,nt3,ans,cnt;
struct manba{
	long long a,num;
}tr[200010][3];
bool cmp(manba x,manba y)
{
	if(x.a>y.a){return 1;}
	else return 0;
}
long long n,m,T;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		ans=0;
		cnt=0;
		nt1=nt2=nt3=0;
		memset(tr,0,sizeof(tr));
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>tr[1][i].a>>tr[2][i].a>>tr[3][i].a;
			tr[1][i].num=i;
			tr[2][i].num=i;
			tr[3][i].num=i;
		}
		sort(tr[1]+1,tr[1]+n+1,cmp);
		sort(tr[2]+1,tr[2]+n+1,cmp);
		sort(tr[3]+1,tr[3]+n+1,cmp);
		q1=q2=q3=1;
		long long mx=0;
		while(cnt<=n)
		{
//			cout<<q1<<" "<<q2<<" "<<q3<<endl;
			mx=0;
			while(vis[tr[1][q1].num]==1)
			{
				q1++;
			}
			while(vis[tr[2][q2].num]==1)
			{
				q2++;
			}
			while(vis[tr[3][q3].num]==1)
			{
				q3++;
			}
			if(nt1<n/2)
			{
				mx=max(mx,tr[1][q1].a);
			}
			if(nt2<n/2)
			{
				mx=max(mx,tr[2][q2].a);
			}
			if(nt3<n/2)
			{
				mx=max(tr[3][q3].a,mx);
			}
			if(mx==tr[1][q1].a&&nt1<n/2)
			{
				cnt++;
				nt1++;
//				cout<<"1wun    "<<endl;
				vis[tr[1][q1].num]=1;
				ans+=tr[1][q1].a;
			}
			else if(mx=tr[2][q2].a&&nt2<n/2)
			{
				cnt++;
//				cout<<"2wun"<<endl;
				nt2++;
				vis[tr[2][q2].num]=1;
				ans+=tr[2][q2].a;
			}
			else if(nt3<n/2)
			{
				cnt++;
//				cout<<"3wun"<<endl;
				nt3++;
				vis[tr[3][q3].num]=1;
				ans+=tr[3][q3].a;
			}
			if(cnt==n)
			{
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
