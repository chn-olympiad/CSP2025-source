#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n;
long long a[100050];
long long b[100050];
long long c[100050];
long long s[100050];
long long u[100050];
int ca,cb,cc;
long long ans;
inline void mn(int I)
{
	cin>>n;
	ca=cb=cc=0;
	priority_queue<long long> qa,qb,qc;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		s[i]=max(a[i],max(b[i],c[i]));
		u[i]=(s[i]==a[i]?max(b[i],c[i]):(s[i]==b[i]?max(a[i],c[i]):max(a[i],b[i])));
	}
	for(int i=1;i<=n;i++)
	{
		ans+=s[i];
		if(s[i]==a[i])
		{
			//cout<<i<<'a'<<' '<<u[i]-s[i]<<'\n';
			ca++;
			qa.push(u[i]-s[i]);
		}
		else if(s[i]==b[i])
		{
			//cout<<i<<'b'<<' '<<u[i]-s[i]<<'\n';
			cb++;
			qb.push(u[i]-s[i]);
		}
		else
		{
			//cout<<i<<'c'<<' '<<u[i]-s[i]<<'\n';
			cc++;
			qc.push(u[i]-s[i]);
		}
	}
	n/=2;
	while(ca>n)
	{
		ans+=qa.top();
		qa.pop();
		ca--;
	}
	while(cb>n)
	{
		ans+=qb.top();
		qb.pop();
		cb--;
	}
	while(cc>n)
	{
		ans+=qc.top();
		qc.pop();
		cc--;
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) mn(T+1);
	return 0;
}
