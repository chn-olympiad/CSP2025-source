#include<bits/stdc++.h>
using namespace std;
int t,n,f[600005],x[600005][4];
queue<pair<int,int> > ss1;
queue<pair<int,int> > ss2;
queue<pair<int,int> > ss3;
struct stu
{
	int b,id,bm;
}a[600005];
bool cmp(stu w,stu u)
{
	return w.b>u.b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(f,0,sizeof(f));
		long long cnt=1,ans=0;
		map<int,int> v;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>x[i][j]; 
				a[cnt].b=x[i][j];
				a[cnt].id=i;
				a[cnt].bm=j;
				cnt++;
			}	
		}
		sort(a+1,a+cnt,cmp);
		for(int i=1;i<cnt;i++)
		{
			if(v[a[i].bm]<(n/2)&&f[a[i].id]==0)
			{
				v[a[i].bm]++;
				f[a[i].id]=1;
				if(a[i].bm==1)
				{
					ss1.push({a[i].b,a[i].id});
				}
				else if(a[i].bm==2)
				{
					ss2.push({a[i].b,a[i].id});
				}
				else
				{
					ss3.push({a[i].b,a[i].id});
				}
				ans+=a[i].b;
			}
			else if(v[a[i].bm]>=(n/2)&&f[a[i].id]==0)
			{
				if(a[i].bm==1)
				{
					int tou=ss1.front().second;
					int wei=ss1.front().first;
					int he1=a[i].b+x[tou][2];
					int he2=wei+x[a[i].id][2];
					if(he1>he2)
					{
						ss1.pop();
						ss1.push({a[i].b,a[i].id});
						ans-=wei;
						ans+=a[i].b;
						if(v[2]<(n/2))
						{
							ss2.push({wei,tou});
							ans+=x[tou][2];
							v[2]++;
						}
					}
					else
					{
						tou=ss1.front().second;
						wei=ss1.front().first;
						he1=a[i].b+x[tou][3];
						he2=wei+x[a[i].id][3];
						if(he1>he2)
						{
							ss1.pop();
							ss1.push({a[i].b,a[i].id});
							ans-=wei;
							ans+=a[i].b;
							if(v[3]<(n/2))
							{
								ss3.push({wei,tou});
								ans+=x[tou][3];
								v[3]++;
							}
						}
					}
				}
				if(a[i].bm==2)
				{
					int tou=ss2.front().second;
					int wei=ss2.front().first;
					int he1=a[i].b+x[tou][1];
					int he2=wei+x[a[i].id][1];
					if(he1>he2)
					{
						ss2.pop();
						ss2.push({a[i].b,a[i].id});
						ans-=wei;
						ans+=a[i].b;
						if(v[1]<(n/2))
						{
							ss1.push({wei,tou});
							ans+=x[tou][1];
							v[1]++;
						}
					}
					else
					{
						tou=ss2.front().second;
						wei=ss2.front().first;
						he1=a[i].b+x[tou][3];
						he2=wei+x[a[i].id][3];
						if(he1>he2)
						{
							ss2.pop();
							ss2.push({a[i].b,a[i].id});
							ans-=wei;
							ans+=a[i].b;
							if(v[3]<(n/2))
							{
								ss3.push({wei,tou});
								ans+=x[tou][3];
								v[3]++;
							}
						}
					}
				}
				if(a[i].bm==3)
				{
					int tou=ss3.front().second;
					int wei=ss3.front().first;
					int he1=a[i].b+x[tou][1];
					int he2=wei+x[a[i].id][1];
					if(he1>he2)
					{
						ss3.pop();
						ss3.push({a[i].b,a[i].id});
						ans-=wei;
						ans+=a[i].b;
						if(v[1]<(n/2))
						{
							ss1.push({wei,tou});
							ans+=x[tou][1];
							v[1]++;
						}
					}
					else
					{
						tou=ss3.front().second;
						wei=ss3.front().first;
						he1=a[i].b+x[tou][2];
						he2=wei+x[a[i].id][2];
						if(he1>he2)
						{
							ss3.pop();
							ss3.push({a[i].b,a[i].id});
							ans-=wei;
							ans+=a[i].b;
							if(v[2]<(n/2))
							{
								ss2.push({wei,tou});
								ans+=x[tou][2];
								v[2]++;
							}
						}
					}
				}
			}
		}
		while(!ss1.empty())
		{
			ss1.pop();
		}
		while(!ss2.empty())
		{
			ss2.pop();
		}
		while(!ss3.empty())
		{
			ss3.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}
