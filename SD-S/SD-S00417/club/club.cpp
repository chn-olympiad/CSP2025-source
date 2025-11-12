#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=1e5+10;
int a[5][N]; 
int cnt[5];
struct pr{
	int val,id;
};
struct dxj{
	int x,y,c,loc;
	bool operator<(const dxj nw)const
	{
		return this->c>nw.c;
	}
};
priority_queue<dxj> q[5];
pr ck1(int m)
{
	int val=0,id=0;
	if(a[1][m]>=a[2][m]) val=a[1][m],id=1;
	else val=a[2][m],id=2;
	if(val<a[3][m]) val=a[3][m],id=3;
	return (pr){val,id};
}
pr ck2(int m,int f)
{
	if(f==1) return a[2][m]<=a[3][m]?(pr){a[3][m],3}:(pr){a[2][m],2};
	if(f==2) return a[1][m]<=a[3][m]?(pr){a[3][m],3}:(pr){a[1][m],1};
	if(f==3) return a[2][m]<=a[1][m]?(pr){a[1][m],1}:(pr){a[2][m],2};		
}
pr ck3(int m,int f,int s)
{
	return (pr){a[6-f-s][m],6-f-s};
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[j][i]; cnt[j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			pr f=ck1(i);
			pr s=ck2(i,f.id);
			if(cnt[f.id]<n/2)
			{
				q[f.id].push((dxj){f.val,s.id,f.val-s.val,i});
				cnt[f.id]++;
				continue;
			}
			else
			{
				//此处超过一半则其他位置一定小于一半不需考虑换班时换到的班是否超人数 
				dxj t=q[f.id].top();
				if(t.c<f.val-s.val)// 换了更优 ,且一定不会被换回来 
				{
					// 当前的要加入f班  t要换走
					int to=ck2(t.loc,f.id).id;
					cnt[to]++;
					pr th=ck3(t.loc,f.id,t.y);
					q[to].push((dxj){a[t.y][t.loc],th.id,a[t.y][t.loc]-th.val,t.loc});
					q[f.id].pop();  
					q[f.id].push((dxj){f.val,s.id,f.val-s.val,i});
				}
				else// 不换更优 
				{
					pr th=ck3(i,f.id,s.id);
					cnt[s.id]++;
					q[s.id].push((dxj){s.val,th.id,s.val-th.val,i});
				}				
			}
		}
		ll ans=0;
		while(!q[1].empty())
		{
			ans=ans+q[1].top().x*1ll;
			q[1].pop();
		}
		while(!q[2].empty())
		{
			ans=ans+q[2].top().x*1ll;
			q[2].pop();
		}
		while(!q[3].empty())
		{
			ans=ans+q[3].top().x*1ll;
			q[3].pop();
		}			
		cout<<ans<<"\n";	
	}						
			
							
	return 0;
}

