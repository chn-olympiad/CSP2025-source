#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node
{
	int mx,mn,num;
}a[N];
bool cmp(node x,node y)
{
	return x.mx-x.mn<y.mx-y.mn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,s=0;
		cin>>n;
		int m=n/2;
		int c[4]={0,0,0,0};
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			int flag=1;
			if(x>y)swap(x,y);
			else flag=2;
			if(y>z)swap(y,z);
			else flag=3;
			if(x>y)swap(x,y);
			a[i].mx=z;
			a[i].mn=y;
			a[i].num=flag;
			s+=z;
			c[flag]++;
//			cout<<a[i].mx<<' '<<a[i].mn<<' '<<a[i].num<<endl;
		}
		for(int i=1;i<=3;i++)
		{
			if(c[i]<=m)continue;
			sort(a+1,a+n+1,cmp);
			for(int j=1;j<=n&&c[i]>m;j++)
			{
				if(a[j].num!=i)continue;
				c[i]--;
				s-=a[j].mx-a[j].mn;
			}
			break;
		}
		cout<<s<<'\n';
//		cout<<"\n\n\n\n\n\n\n";
	}
	return 0;
}
