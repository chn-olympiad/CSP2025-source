#include<bits/stdc++.h>
#define ll long long
#define pq priority_queue
#define pr pair
#define vec vector
/*
feropen
mian
itn
y0
ans
CCF
Never Gonna Give You UP~
guanzhu luogu@chenyuheng01 thank you miao~
log:
[14:26]:enter
[14:34]:start T1 5pts
[14:40]:end T1 5pts
*/
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		pq<int> que;
		int n;
		cin>>n;
		if(n==2)
		{
			int ret=0;
			bool m1=0,m2=0,m3=0;
			int a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>f;
			int mxnum=max(max(a,b),max(c,max(d,max(e,f))));
			if(mxnum==max(max(a,b),c))
			{
				if(mxnum==a) m1=1;
				else if(mxnum==b) m2=1;
				else if(mxnum==c) m3=1;
				ret+=mxnum;
				if(m1) ret+=max(e,f);
				else if(m2) ret+=max(d,f);
				else if(m3) ret+=max(d,e);
				cout<<ret<<endl;
				continue; 
			}
			else
			{
				if(mxnum==d) m1=1;
				else if(mxnum==e) m2=1;
				else if(mxnum==f) m3=1;
				ret+=mxnum;
				if(m1) ret+=max(b,c);
				else if(m2) ret+=max(a,c);
				else if(m3) ret+=max(a,b);
				cout<<ret<<endl;
				continue;
				
			}
		}
		for(int i=0;i<n;i++)
		{
			int q,w,a;
			cin>>q>>w>>a;
			que.push(q);
		}
		int ret=0;
		int tmp=n/2;
		while(tmp--)
		{
			ret+=que.top();
			que.pop();
		}
		cout<<ret;
		cout<<endl;
	}
}