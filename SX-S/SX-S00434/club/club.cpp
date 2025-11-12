#include<bits/stdc++.h>
using namespace std;
int tt,n,w[4],t[4],x,tl[4],htl[4],ts,tts,ans;
struct node
{
	int ss[4],zx,cx,zbx;
}a[100005];
struct node2
{
	int z,id;
}wer[4][100005];
bool cmp(node2 u,node2 y)
{
	return u.z<y.z;
}
bool cmp2(node2 u,node2 y)
{
	return u.z>y.z;
}
void dfs(int step,int sx)
{
	if(step>n)
	{
		ans=max(ans,sx);
		return;
	}
	if(t[1]<x)
	{
		t[1]++;
		dfs(step+1,sx+a[step].ss[1]);
		t[1]--;
	}
	if(t[2]<x)
	{
		t[2]++;
		dfs(step+1,sx+a[step].ss[2]);
		t[2]--;
	}
	if(t[3]<x)
	{
		t[3]++;
		dfs(step+1,sx+a[step].ss[3]);
		t[3]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>tt;
	while(tt--)
	{
		cin>>n;
		x=n/2;
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=htl[i];j++)
			{
				wer[i][j].z=0;
				wer[i][j].id=0;
			}
			w[i]=0;
			t[i]=0;
			tl[i]=0;
			htl[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].ss[1]>>a[i].ss[2]>>a[i].ss[3];
			if(a[i].ss[1]>=a[i].ss[2]&&a[i].ss[1]>=a[i].ss[3])
			{
				a[i].zx=1;
				if(a[i].ss[2]>=a[i].ss[3])
				{
					a[i].cx=2;
					a[i].zbx=3;
				}
				else
				{
					a[i].cx=3;
					a[i].zbx=2;
				}
			}
			else if(a[i].ss[2]>=a[i].ss[1]&&a[i].ss[2]>=a[i].ss[3])
			{
				a[i].zx=2;
				if(a[i].ss[1]>=a[i].ss[3])
				{
					a[i].cx=1;
					a[i].zbx=3;
				}
				else
				{
					a[i].cx=3;
					a[i].zbx=1;
				}
			}
			else
			{
				a[i].zx=3;
				if(a[i].ss[1]>=a[i].ss[2])
				{
					a[i].cx=1;
					a[i].zbx=2;
				}
				else
				{
					a[i].cx=2;
					a[i].zbx=1;
				}
			}
			tl[a[i].zx]++;
			wer[a[i].zx][tl[a[i].zx]].z=a[i].ss[a[i].zx];
			wer[a[i].zx][tl[a[i].zx]].id=i;
		}
		sort(wer[1]+1,wer[1]+tl[1]+1,cmp);
		sort(wer[2]+1,wer[2]+tl[2]+1,cmp);
		sort(wer[3]+1,wer[3]+tl[3]+1,cmp);
		if(n<18)
		{
			dfs(1,0);
			cout<<ans<<endl;
			ans=0;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			int mxid=0,mx=-1e9;
			for(int j=1;j<=3;j++)
			{
				if(wer[j][htl[j]].z>mx)
				{
					mx=max(mx,wer[j][htl[j]].z);
					mxid=j;
				}
			}
			if(t[mxid]<x)
			{
				t[mxid]++;
				w[mxid]+=a[wer[mxid][htl[mxid]].id].ss[mxid];
			}
			else
			{
				t[a[mxid].cx]++;
				w[a[mxid].cx]+=a[wer[mxid][htl[mxid]].id].ss[a[mxid].cx];
			}
			htl[mxid]++;
		}
		ts=w[1]+w[2]+w[3];
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=htl[i];j++)
			{
				wer[i][j].z=0;
				wer[i][j].id=0;
			}
			w[i]=0;
			t[i]=0;
			tl[i]=0;
			htl[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			tl[a[i].zx]++;
			wer[a[i].zx][tl[a[i].zx]].z=a[i].ss[a[i].zx];
			wer[a[i].zx][tl[a[i].zx]].id=i;
		}
		sort(wer[1]+1,wer[1]+tl[1]+1,cmp2);
		sort(wer[2]+1,wer[2]+tl[2]+1,cmp2);
		sort(wer[3]+1,wer[3]+tl[3]+1,cmp2);
		for(int i=1;i<=n;i++)
		{
			int mxid=0,mx=-1e9;
			for(int j=1;j<=3;j++)
			{
				if(wer[j][htl[j]].z>mx)
				{
					mx=max(mx,wer[j][htl[j]].z);
					mxid=j;
				}
			}
			if(t[mxid]<x)
			{
				t[mxid]++;
				w[mxid]+=a[wer[mxid][htl[mxid]].id].ss[mxid];
			}
			else
			{
				t[a[mxid].cx]++;
				w[a[mxid].cx]+=a[wer[mxid][htl[mxid]].id].ss[a[mxid].cx];
			}
			htl[mxid]++;
		}
		tts=w[1]+w[2]+w[3];
		cout<<max(ts,tts)<<endl;
	}
	return 0;
}