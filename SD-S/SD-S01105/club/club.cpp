#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll T,n,maxn,ans,cnt1,cnt2,cnt3;
bool use[N],cas1=1,cas2=1; 
struct node
{
	ll a1,a2,a3,cha1,cha2,cha3,id;
}mem[N],mem1[N],mem2[N],mem3[N];
bool cmp1(node x,node y)
{
	if(x.a1==y.a1)
	{
		if(x.a2==y.a2) return x.a3<y.a3;
		return x.a2<y.a2;
	}
	return x.a1>y.a1;
}
bool cmp2(node x,node y)
{
	if(x.a2==y.a2)
	{
		if(x.a1==y.a1) return x.a3<y.a3;
		return x.a1<y.a1;
	}
	return x.a2>y.a2;
}
bool cmp3(node x,node y)
{
	if(x.a3==y.a3)
	{
		if(x.a1==y.a1) return x.a2<y.a2;
		return x.a1<y.a1;
	}
	return x.a3>y.a3;
}
bool cmpa1(node x,node y)
{
	return x.cha1>y.cha1;
}
bool cmpa2(node x,node y)
{
	return x.cha2>y.cha2;
}
bool cmpa3(node x,node y)
{
	return x.cha3>y.cha3;
}
void dfs(ll num,ll sum,ll cnta1,ll cnta2,ll cnta3)
{
	if(cnta1>maxn||cnta2>maxn||cnta3>maxn) return;
	if(num==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	use[num]=1;
	dfs(num+1,sum+mem[num].a1,cnta1+1,cnta2,cnta3);
	dfs(num+1,sum+mem[num].a2,cnta1,cnta2+1,cnta3);
	dfs(num+1,sum+mem[num].a3,cnta1,cnta2,cnta3+1);
	use[num]=0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cas1=1;
		cas2=1;
		memset(use,0,sizeof(use));
		scanf("%lld",&n);
		maxn=n/2;
		ans=cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&mem[i].a1,&mem[i].a2,&mem[i].a3);
			mem[i].cha1=mem[i].a1-mem[i].a2-mem[i].a3;
			mem[i].cha2=mem[i].a2-mem[i].a1-mem[i].a3;
			mem[i].cha3=mem[i].a3-mem[i].a1-mem[i].a2;
			mem[i].id=i;
			
			mem1[i].a1=mem[i].a1;
			mem1[i].a2=mem[i].a2;
			mem1[i].a3=mem[i].a3;
			mem1[i].cha1=mem[i].cha1;
			mem1[i].cha2=mem[i].cha2;
			mem1[i].cha3=mem[i].cha3;
			mem1[i].id=mem[i].id;
			
			mem2[i].a1=mem[i].a1;
			mem2[i].a2=mem[i].a2;
			mem2[i].a3=mem[i].a3;
			mem2[i].cha1=mem[i].cha1;
			mem2[i].cha2=mem[i].cha2;
			mem2[i].cha3=mem[i].cha3;
			mem2[i].id=mem[i].id;
			
			mem3[i].a1=mem[i].a1;
			mem3[i].a2=mem[i].a2;
			mem3[i].a3=mem[i].a3;
			mem3[i].cha1=mem[i].cha1;
			mem3[i].cha2=mem[i].cha2;
			mem3[i].cha3=mem[i].cha3;
			mem3[i].id=mem[i].id;
			if(mem[i].a3!=0)
			{
				cas1=0;
				cas2=0;
			}
			if(mem[i].a2!=0) cas1=0;
		}
		if(cas1)
		{
			sort(mem+1,mem+n+1,cmp1);
			for(int i=1;i<=maxn;i++)
			{
				ans+=mem[i].a1;
			}
			cout<<ans<<endl;
			continue;
		}
		if(cas2)
		{
			int cnt1=0,cnt2=0;
			sort(mem+1,mem+n+1,cmpa1);
			for(int i=1;i<=maxn;i++)
			{
				ans+=mem[i].a1;
			}
			for(int i=n;i>=n-maxn+1;i--)
			{
				ans+=mem[i].a2;
			}
			cout<<ans<<endl;
			continue;
		}
		if(n<=10)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		/*-----------Accepted_Error-----------*/
//		cout<<maxn<<endl;
		sort(mem1+1,mem1+n+1,cmpa1);
		for(int i=1;i<=n;i++)
		{
			if(!use[mem1[i].id]&&mem1[i].cha1>0&&cnt1<maxn)
			{
				cnt1++;
				use[mem1[i].id]=1;
				ans+=mem1[i].a1; 
			}
			if(mem1[i].cha1<=0) break;
		}
		
		sort(mem2+1,mem2+n+1,cmpa2);
		for(int i=1;i<=n;i++)
		{
			if(!use[mem2[i].id]&&mem2[i].cha2>0&&cnt2<maxn)
			{
				cnt2++;
				use[mem2[i].id]=1;
				ans+=mem2[i].a2; 
			}
			if(mem2[i].cha1<=0) break;
		}
		
		sort(mem3+1,mem3+n+1,cmpa3);
		for(int i=1;i<=n;i++)
		{
			if(!use[mem3[i].id]&&mem3[i].cha3>0&&cnt3<maxn)
			{
				cnt3++;
				use[mem3[i].id]=1;
				ans+=mem3[i].a3; 
			}
			if(mem3[i].cha1<=0) break;
		}
		
		sort(mem+1,mem+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
			if(use[mem[i].id]||(mem[i].a1<mem[i].a2&&cnt2<maxn)||(mem[i].a1<mem[i].a3&&cnt3<maxn)) continue;
			if(!use[mem[i].id]&&cnt1<maxn)
			{
				cnt1++;
				use[mem[i].id]=1;
				ans+=mem[i].a1;
			}
			if(cnt1==maxn) break;
		}
		
		sort(mem+1,mem+n+1,cmp2);
		for(int i=1;i<=n;i++)
		{
			if(use[mem[i].id]||(mem[i].a2<mem[i].a1&&cnt1<maxn)||(mem[i].a2<mem[i].a3&&cnt3<maxn)) continue;
			if(!use[mem[i].id]&&cnt2<maxn)
			{
				cnt2++;
				use[mem[i].id]=1;
				ans+=mem[i].a2;
			}
			if(cnt2==maxn) break;
		}
		
		sort(mem+1,mem+n+1,cmp3);
		for(int i=1;i<=n;i++)
		{
			if(use[mem[i].id]||(mem[i].a3<mem[i].a1&&cnt1<maxn)||(mem[i].a3<mem[i].a2&&cnt2<maxn)) continue;
			if(!use[mem[i].id]&&cnt3<maxn)
			{
				cnt3++;
				use[mem[i].id]=1;
				ans+=mem[i].a3;
			}
			if(cnt3==maxn) break;
		}
		
		for(int i=1;i<=n;i++)
		{
			if(!use[mem[i].id])
			{
				if(mem[i].a1>mem[i].a2)
				{
					if(mem[i].a2>mem[i].a3)
					{
						if(cnt1!=maxn)
						{
							cnt1++;
							ans+=mem[i].a1;
							use[mem[i].id]=1;
						}
						else if(cnt2!=maxn)
						{
							cnt2++;
							ans+=mem[i].a2;
							use[mem[i].id]=1;
						}
						else
						{
							cnt3++;
							ans+=mem[i].a3;
							use[mem[i].id]=1;
						}
					}
					else
					{
						if(cnt1!=maxn)
						{
							cnt1++;
							ans+=mem[i].a1;
							use[mem[i].id]=1;
						}
						else if(cnt3!=maxn)
						{
							cnt3++;
							ans+=mem[i].a3;
							use[mem[i].id]=1;
						}
						else
						{
							cnt2++;
							ans+=mem[i].a2;
							use[mem[i].id]=1;
						}
					}
				}
				else
				{
					if(mem[i].a1>mem[i].a3)
					{
						if(cnt2!=maxn)
						{
							cnt2++;
							ans+=mem[i].a2;
							use[mem[i].id]=1;
						}
						else if(cnt1!=maxn)
						{
							cnt1++;
							ans+=mem[i].a1;
							use[mem[i].id]=1;
						}
						else
						{
							cnt3++;
							ans+=mem[i].a3;
							use[mem[i].id]=1;
						}
					}
					else
					{
						if(cnt2!=maxn)
						{
							cnt2++;
							ans+=mem[i].a2;
							use[mem[i].id]=1;
						}
						else if(cnt3!=maxn)
						{
							cnt3++;
							ans+=mem[i].a3;
							use[mem[i].id]=1;
						}
						else
						{
							cnt1++;
							ans+=mem[i].a1;
							use[mem[i].id]=1;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//贪心，第i个社员被分配至第j个社团贡献最大
//如果第i名同学的a1最大，贡献比a2和a3加起来都大，那么一定进1，选择三个队 
//如果第i名同学的a1是三个数中最大的，那么考虑名额还没满时将其放入1
/*hack:
4
1 2 3
4 5 7
7 8 9
10 11 12
29
*/
//不能只考虑先填入1社团 
//40pts
