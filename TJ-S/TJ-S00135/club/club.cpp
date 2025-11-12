#include<bits/stdc++.h>
using namespace std;
int n,m,l,o,p,q;
struct node{
	int x,y,z;
}a[100005];
struct node1{
	int r,s;
	bool operator<(const node1 &b)const{return s-max(a[r].y,a[r].z)>b.s-max(a[b.r].y,a[b.r].z);};
	node1(int c,int d){r=c;s=d;}
};
struct node2{
	int t,u;
	bool operator<(const node2 &b)const{return u-max(a[t].x,a[t].z)>b.u-max(a[b.t].x,a[b.t].z);};
	node2(int c,int d){t=c;u=d;}
};
struct node3{
	int v,w;
	bool operator<(const node3 &b)const{return w-max(a[v].x,a[v].y)>b.w-max(a[b.v].x,a[b.v].y);};
	node3(int c,int d){v=c;w=d;}
};
priority_queue <node1> pq1;
priority_queue <node2> pq2;
priority_queue <node3> pq3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			cin>>a[j].x>>a[j].y>>a[j].z;
			if(max(a[j].x,max(a[j].y,a[j].z))==a[j].x)
			{
				o++;
				if(o>m/2)
				{
					o--;
					if(a[j].x-max(a[j].y,a[j].z)<pq1.top().s-max(a[pq1.top().r].y,a[pq1.top().r].z))
					{
						if(max(a[j].y,a[j].z)==a[j].y)
						{
							p++;
							pq2.push(node2(j,a[j].y));
							l+=a[j].y;
						}
						else
						{
							q++;
							pq3.push(node3(j,a[j].z));
							l+=a[j].z;
						}
						continue;
					}
					if(max(a[pq1.top().r].y,a[pq1.top().r].z)==a[pq1.top().r].y)
					{
						p++;
						pq2.push(node2(pq1.top().r,a[pq1.top().r].y));
						l+=a[pq1.top().r].y;
					}
					else
					{
						q++;
						pq3.push(node3(pq1.top().r,a[pq1.top().r].z));
						l+=a[pq1.top().r].z;
					}
					l-=pq1.top().s;
					pq1.pop();
				}
				pq1.push(node1(j,a[j].x));
				l+=a[j].x;
				continue;
			}
			if(max(a[j].x,max(a[j].y,a[j].z))==a[j].y)
			{
				p++;
				if(p>m/2)
				{
					p--;
					if(a[j].y-max(a[j].x,a[j].z)<pq2.top().u-max(a[pq2.top().t].x,a[pq2.top().t].z))
					{
						if(max(a[j].x,a[j].z)==a[j].x)
						{
							o++;
							pq1.push(node1(j,a[j].x));
							l+=a[j].x;
						}
						else
						{
							q++;
							pq3.push(node3(j,a[j].z));
							l+=a[j].z;
						}
						continue;
					}
					if(max(a[pq2.top().t].x,a[pq2.top().t].z)==a[pq2.top().t].x)
					{
						o++;
						pq1.push(node1(pq2.top().t,a[pq2.top().t].x));
						l+=a[pq2.top().t].x;
					}
					else
					{
						q++;
						pq3.push(node3(pq2.top().t,a[pq2.top().t].z));
						l+=a[pq2.top().t].z;
					}
					l-=pq2.top().u;
					pq2.pop();
				}
				pq2.push(node2(j,a[j].y));
				l+=a[j].y;
				continue;
			}
			if(max(a[j].x,max(a[j].y,a[j].z))==a[j].z)
			{
				q++;
				if(q>m/2)
				{
					q--;
					if(a[j].z-max(a[j].x,a[j].y)<pq3.top().w-max(a[pq3.top().v].x,a[pq3.top().v].y))
					{
						if(max(a[j].x,a[j].y)==a[j].x)
						{
							o++;
							pq1.push(node1(j,a[j].x));
							l+=a[j].x;
						}
						else
						{
							p++;
							pq2.push(node2(j,a[j].y));
							l+=a[j].y;
						}
						continue;
					}
					if(max(a[pq3.top().v].x,a[pq3.top().v].y)==a[pq3.top().v].x)
					{
						o++;
						pq1.push(node1(pq3.top().v,a[pq3.top().v].x));
						l+=a[pq3.top().v].x;
					}
					else
					{
						p++;
						pq2.push(node2(pq3.top().v,a[pq3.top().v].y));
						l+=a[pq3.top().v].y;
					}
					l-=pq3.top().w;
					pq3.pop();
				}
				pq3.push(node3(j,a[j].z));
				l+=a[j].z;
				continue;
			}
		}
		cout<<l<<endl;
		while(!pq1.empty())pq1.pop();
		while(!pq2.empty())pq2.pop();
		while(!pq3.empty())pq3.pop();
		l=0;
		o=0;
		p=0;
		q=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
