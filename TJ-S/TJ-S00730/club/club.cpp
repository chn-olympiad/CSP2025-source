#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
struct node
{
	long ind,val;
};
long t,n,ans,m1,m2,m3,n1,n2,n3,tmp;
long a[100050];
long b[100050];
long c[100050];
node d[100050];
bool cmp(node x,node y)
{
	return x.val > y.val;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans = m1 = m2 = m3 = 0;
		for(long i = 1;i <= n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i] >= b[i]&&a[i] >= c[i])
				m1++;
			else if(b[i] >= a[i]&&b[i] >= c[i])
				m2++;
			else
				m3++;
		}
		if(m2 < m3)
		{
			for(long i = 1;i <= n;i++)
			{
				tmp = c[i];
				c[i] = b[i];
				b[i] = tmp;
			}
			tmp = m3;
			m3 = m2;
			m2 = tmp;
		}
		if(m1 < m2)
		{
			for(long i = 1;i <= n;i++)
			{
				tmp = a[i];
				a[i] = b[i];
				b[i] = tmp;
			}
			tmp = m1;
			m1 = m2;
			m2 = tmp;
		}
		if(m2 < m3)
		{
			for(long i = 1;i <= n;i++)
			{
				tmp = c[i];
				c[i] = b[i];
				b[i] = tmp;
			}
		}
		m1 = m2 = m3 = ans = 0;
		for(long i = 1;i <= n;i++)
		{
			if(a[i] >= b[i]&&a[i] >= c[i])
			{
				d[++m1].ind = i;
				d[m1].val = a[i]-max(c[i],b[i]);
			}
			else if(b[i] >= a[i]&&b[i] >= c[i])
				ans+=b[i];
			else
				ans+=c[i];
		}
		sort(d+1,d+1+m1,cmp);
		for(long i = 1;i <= min(n/2,m1);i++)
			ans+=a[d[i].ind];
		if(m1 > n/2)
		{
			for(long i = n/2+1;i <= m1;i++)
				ans+=max(b[d[i].ind],c[d[i].ind]);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
