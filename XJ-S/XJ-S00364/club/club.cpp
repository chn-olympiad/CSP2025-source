#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
int a[maxn],b[maxn],c[maxn]; 
priority_queue<int> q1,q2,q3;
void solve()
{
	cin>>n;
	long long ans=0;
	while(q1.size()) q1.pop();
	while(q2.size()) q2.pop();
	while(q3.size()) q3.pop();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		int t=max(max(a[i],b[i]),c[i]);
		if(t==a[i])
		{
			ans+=a[i];
			if(b[i]>=c[i]) q1.push(b[i]-a[i]);
			else q1.push(c[i]-a[i]);
		}
		else if(t==b[i])
		{
			ans+=b[i];
			if(a[i]>=c[i]) q2.push(a[i]-b[i]);
			else q2.push(c[i]-b[i]);
		}
		else 
		{
			ans+=c[i];
			if(a[i]>=b[i]) q3.push(a[i]-c[i]);
			else q3.push(b[i]-c[i]);
		}
	}
	while(q1.size()>n/2) {
		ans+=q1.top();q1.pop();
	}
	while(q2.size()>n/2) {
		ans+=q2.top();q2.pop();
	}
	while(q3.size()>n/2) {
		ans+=q3.top();q3.pop();
	}
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		solve(); 
	}
	return 0;
}

