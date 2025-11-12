#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
priority_queue<int,vector<int>,greater<int> >pq[5];
int a[N],b[N],c[N];
int cnt[10];
void init()
{
	cnt[1]=cnt[2]=cnt[3]=0;
	while(!pq[1].empty())
	{
		pq[1].pop();
	}
	while(!pq[2].empty())
	{
		pq[2].pop();
	}
	while(!pq[3].empty())
	{
		pq[3].pop();
	}
}
void solve()
{
	int n,ans=0;
	cin>>n;
	init();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	//	cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
		if(a[i]>=b[i]&&a[i]>=c[i])
		{
			cnt[1]++,ans+=a[i];
	//		cout<<1<<endl;
			if(cnt[1]>n/2)
			{
				cnt[1]--;
				if(pq[1].top()<a[i]-max(b[i],c[i]))
				{
					ans-=pq[1].top();
					pq[1].pop();
					pq[1].push(a[i]-max(b[i],c[i]));
				}
				else
				{
					ans=ans-a[i]+max(b[i],c[i]);
				}
			}
			else
			{
				pq[1].push(a[i]-max(b[i],c[i]));
			}
		}
		else
		{
			if(b[i]>=a[i]&&b[i]>=c[i])
			{
				cnt[2]++,ans+=b[i];
	//			cout<<2<<endl;
				if(cnt[2]>n/2)
				{
					cnt[2]--;
					if(pq[2].top()<b[i]-max(a[i],c[i]))
					{
						ans-=pq[2].top();
						pq[2].pop();
						pq[2].push(b[i]-max(a[i],c[i]));
					}
					else
					{
						ans=ans-b[i]+max(a[i],c[i]);
					}
				}
				else
				{
					pq[2].push(b[i]-max(a[i],c[i]));
				}
			}
			else
			{
				cnt[3]++,ans+=c[i];
		//		cout<<3<<endl;
				if(cnt[3]>n/2)
				{
					cnt[3]--;
					if(pq[3].top()<c[i]-max(a[i],b[i]))
					{
						ans-=pq[3].top();
		//				cout<<pq[3].top()<<endl;
						pq[3].pop();
						pq[3].push(c[i]-max(a[i],b[i]));
					}
					else
					{
		//				cout<<-1<<endl;
						ans=ans-c[i]+max(a[i],b[i]);
					}
					
				}
				else
				{
					pq[3].push(c[i]-max(a[i],b[i]));
		//			cout<<c[i]-max(a[i],b[i])<<endl;
				}
				
			}
		}
		
	}
	cout<<ans<<endl;
}
int main()
{
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

