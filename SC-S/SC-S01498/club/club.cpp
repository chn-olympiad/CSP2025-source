#include<bits/stdc++.h>
using namespace std;
#define int long long
struct myst{
	int a,b,c;
}e[200005];
int nis[200005];
int maxx,cnt;
int n,ans1,ans2,ans3;
void dfs(int id,int aa,int bb,int cc,int ans)
{
	if(id==n+1)
	{
		maxx=max(ans,maxx);
		return;
	}
	if(aa>=1) dfs(id+1,aa-1,bb,cc,ans+e[id].a);
	if(bb>=1) dfs(id+1,aa,bb-1,cc,ans+e[id].b);
	if(cc>=1) dfs(id+1,aa,bb,cc-1,ans+e[id].c);
}
bool cmp(myst x,myst y)
{
	return max(max(x.a,x.b),x.c)>max(max(y.a,y.b),y.c);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>e[i].a>>e[i].b>>e[i].c;
		}
		sort(e+1,e+1+n,cmp);
		if(n<=10)
		{
			dfs(1,n/2,n/2,n/2,0);
			cout<<maxx<<endl;
		}
		else if(e[1].b==0&&e[1].c==0&&e[2].c==0&&e[2].b==0&&e[3].b==0&&e[3].c==0)
		{
			sort(e+1,e+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				maxx+=max(max(e[i].a,e[i].b),e[i].c);
			}
			cout<<maxx<<endl;
		}
		else
		{
			ans1=0,ans2=0,ans3=0,cnt=0;
			for(int i=1;i<=max(ans1,max(ans2,ans3));i++)
			{
				nis[i]=0;
			}
			for(int i=1;i<=n;i++)
			{
				if(max(max(e[i].a,e[i].b),e[i].c)==e[i].a)
				{
					ans1++;
				}
				else if(max(max(e[i].a,e[i].b),e[i].c)==e[i].b)
				{
					ans2++;
				}
				else
				{
					ans3++;
				}
				maxx+=max(max(e[i].a,e[i].b),e[i].c);
			}
			if(ans1>n/2)
			{
				for(int i=1;i<=n;i++)
				{
					if(max(max(e[i].a,e[i].b),e[i].c)==e[i].a)
					{
						if(max(e[i].b,e[i].c)==e[i].b)
						{
							if(ans2<n/2)
							{
								ans2++;
								nis[++cnt]=e[i].a-e[i].b;
							}
							else
							{
								ans3++;
								nis[++cnt]=e[i].a-e[i].c;
							}
						}
						else
						{
							if(ans3<n/2)
							{
								ans3++;
								nis[++cnt]=e[i].a-e[i].c;
							}
							else
							{
								ans2++;
								nis[++cnt]=e[i].a-e[i].b;
							}
						}
					}
					
				}
				sort(nis+1,nis+1+cnt);
				for(int i=1;i<=(ans1-n/2);i++)
				{
	//				cout<<maxx<<" ";
					maxx-=nis[i];
				}
			}
			cnt=0;
			if(ans2>n/2)
			{
				for(int i=1;i<=n;i++)
				{
					if(max(max(e[i].a,e[i].b),e[i].c)==e[i].b)
					{
						if(max(e[i].a,e[i].c)==e[i].a)
						{
							if(ans1<n/2)
							{
								ans1++;
								nis[++cnt]=e[i].b-e[i].a;
							}
							else
							{
								ans3++;
								nis[++cnt]=e[i].b-e[i].c;
							}
						}
						else
						{
							if(ans3<n/2)
							{
								ans3++;
								nis[++cnt]=e[i].b-e[i].c;
							}
							else
							{
								ans1++;
								nis[++cnt]=e[i].b-e[i].a;
							}
						}
					}
				}
				sort(nis+1,nis+1+cnt);
				for(int i=1;i<=(ans2-n/2);i++)
				{
					maxx-=nis[i];
				}
			}
			cnt=0;
			if(ans3>n/2)
			{
				for(int i=1;i<=n;i++)
				{
					if(max(max(e[i].a,e[i].b),e[i].c)==e[i].c)
					{
						if(max(e[i].a,e[i].b)==e[i].a)
						{
							if(ans1<n/2)
							{
								ans1++;
								nis[++cnt]=e[i].c-e[i].a;
							}
							else
							{
								ans2++;
								nis[++cnt]=e[i].c-e[i].b;
							}
						}
						else
						{
							if(ans2<n/2)
							{
								ans2++;
								nis[++cnt]=e[i].c-e[i].b;
							}
							else
							{
								ans1++;
								nis[++cnt]=e[i].c-e[i].a;
							}
						}
					}
				}
				sort(nis+1,nis+1+cnt);
				for(int i=1;i<=(ans3-n/2);i++)
				{
					maxx-=nis[i];
				}
			}
			cout<<maxx<<endl;
		}
	}
	return 0;
}