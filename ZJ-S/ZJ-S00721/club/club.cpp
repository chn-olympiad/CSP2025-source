#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int t1,t2,t3;
}b[N];
bool cmp(node a,node b)
{
	return max(a.t1,max(a.t2,a.t3))>max(b.t1,max(b.t2,b.t3));
}
int f1[N],f2[N],f3[N],T,n,ans,x1,x2,x3,lst1,lst2,lst3;
queue<int>q1,q2,q3;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>T;
	while(T--)
	{
		ans=0;
		x1=x2=x3=0;
		lst1=lst2=lst3=0;
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>b[i].t1>>b[i].t2>>b[i].t3;	
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			int maxx=max(b[i].t1,max(b[i].t2,b[i].t3));
			if(b[i].t1==maxx)
			{
				if(x1>=n/2)
				{
					queue<int>dq;
					bool flag=0;
					int maxt=0,xt;
					while(!q1.empty())
					{
						int x=q1.front();
						q1.pop();
						dq.push(x);
						if(b[i].t1+max(b[x].t2,b[x].t3)>b[x].t1+max(b[i].t2,b[i].t3))
						{
							flag=1;
							if(b[i].t1+max(b[x].t2,b[x].t3)>maxt)
							{
								maxt=b[i].t1+max(b[x].t2,b[x].t3);
								xt=x;
							}
						}
					}
					if(flag)
					{
						ans-=b[xt].t1;
						ans+=b[i].t1;
						if(b[xt].t2>b[xt].t3)
							q2.push(xt);
						else
							q3.push(xt);
						ans+=max(b[xt].t2,b[xt].t3);
						while(!dq.empty())
						{
							int qt=dq.front();
							if(qt!=xt)
								q1.push(qt);
							dq.pop();
						}
						q1.push(xt);
					}
					else
					{
						if(b[i].t2>b[i].t3)
							q2.push(i);
						else
							q3.push(i);
						while(!dq.empty())
						{
							int qt=dq.front();
							q1.push(qt);
							dq.pop();
						}
						ans+=max(b[i].t2,b[i].t3);	
					}	
				}
				else
				{
					x1++;
					q1.push(i);
					ans+=b[i].t1;
				}
			}
			else if(b[i].t2==maxx)
			{
				if(x2>=n/2)
				{
					queue<int>dq;
					bool flag=0;
					int maxt=0,xt;
					while(!q2.empty())
					{
						int x=q2.front();
						q2.pop();
						dq.push(x);
						if(b[i].t2+max(b[x].t1,b[x].t3)>b[x].t2+max(b[i].t1,b[i].t3))
						{
							flag=1;
							if(b[i].t2+max(b[x].t1,b[x].t3)>maxt)
							{
								maxt=b[i].t2+max(b[x].t1,b[x].t3);
								xt=x;
							}
						}
					}
					if(flag)
					{
						ans-=b[xt].t2;
						ans+=b[i].t2;
						if(b[xt].t1>b[xt].t3)
							q1.push(xt);
						else
							q3.push(xt);
						ans+=max(b[xt].t1,b[xt].t3);
						while(!dq.empty())
						{
							int qt=dq.front();
							if(qt!=xt)
								q2.push(qt);
							dq.pop();
						}
						q2.push(xt);
					}
					else
					{
						if(b[i].t1>b[i].t3)
							q1.push(i);
						else
							q3.push(i);
						while(!dq.empty())
						{
							int qt=dq.front();
							q2.push(qt);
							dq.pop();
						}
						ans+=max(b[i].t1,b[i].t3);	
					}
				}
				else
				{
					x2++;
					q2.push(i);
					ans+=b[i].t2;
				}
			}
			else if(b[i].t3==maxx)
			{
				if(x3>=n/2)
				{
					queue<int>dq;
					bool flag=0;
					int maxt=0,xt;
					while(!q3.empty())
					{
						int x=q3.front();
						q3.pop();
						dq.push(x);
						if(b[i].t3+max(b[x].t1,b[x].t2)>b[x].t3+max(b[i].t1,b[i].t2))
						{
							flag=1;
							if(b[i].t3+max(b[x].t1,b[x].t2)>maxt)
							{
								maxt=b[i].t3+max(b[x].t1,b[x].t2);
								xt=x;
							}
						}
					}
					if(flag)
					{
						ans-=b[xt].t3;
						ans+=b[i].t3;
						if(b[xt].t1>b[xt].t2)
							q1.push(xt);
						else
							q2.push(xt);
						ans+=max(b[xt].t1,b[xt].t2);
						while(!dq.empty())
						{
							int qt=dq.front();
							if(qt!=xt)
								q3.push(qt);
							dq.pop();
						}
						q3.push(xt);
					}
					else
					{
						if(b[i].t1>b[i].t2)
							q1.push(i);
						else
							q2.push(i);
						while(!dq.empty())
						{
							int qt=dq.front();
							q3.push(qt);
							dq.pop();
						}
						ans+=max(b[i].t1,b[i].t2);
					}
						
				}
				else
				{
					x3++;
					q3.push(i);
					ans+=b[i].t3;
				}
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
