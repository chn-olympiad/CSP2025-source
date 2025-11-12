//西安市曲江第一中学
//王钰皓 SN-S00528 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ans;

int T,n;

inline int f(int a,int b,int c)
{
	int t=1,f=a;
	
	if(b>f) t=2,f=b;
	if(c>f) t=3,f=c;
	
	return t;
}

int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>T;
	while(T--)
	{
		priority_queue< int ,vector<int> ,greater<int> > a,b,c;//!!!
		
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			int m,n,d;//!!!
			cin>>m>>n>>d;
			
			int t=f(m,n,d);
			if(t==1)
				a.push(min(m-n,m-d)),ans+=m;
			else if(t==2)
				b.push(min(n-m,n-d)),ans+=n;
			else 
				c.push(min(d-n,d-m)),ans+=d;
		}
		
		while(a.size()>n/2)
		{
			ans-=a.top();
			a.pop();
		}
		while(b.size()>n/2)
		{
			ans-=b.top();
			b.pop();
		}
		while(c.size()>n/2)
		{
			ans-=c.top();
			c.pop();
		}
		
		cout<<ans<<endl;
		
		ans=0;
	}
	
	return 0;
}
