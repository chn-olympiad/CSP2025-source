#include <bits/stdc++.h>
using namespace std;
struct A{
	int q,w,e;
}club1[200010],club2[200010],club3[200010];
int pos1=0,pos2=0,pos3=0;
bool cmp1(A x,A y)
{
	return max(x.q-x.e,x.q-x.w)>max(y.q-y.e,y.q-y.w);
}
bool cmp2(A x,A y)
{
	return max(x.w-x.e,x.w-x.q)>max(y.w-y.e,y.w-y.q);
}
bool cmp3(A x,A y)
{
	return max(x.e-x.w,x.e-x.q)>max(y.e-y.q,y.e-y.w);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int u=1;u<=t;u++)
	{
		pos1=pos2=pos3=0;
		memset(club1,0,sizeof(club1));
		memset(club2,0,sizeof(club2));
		memset(club3,0,sizeof(club3));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int z,x,c;
			cin>>z>>x>>c;
			if(z>=x&&z>=c)
			{
				club1[++pos1].q=z;
				club1[pos1].w=x;
				club1[pos1].e=c;
			}
			else if(x>=z&&x>=c)
			{
				club2[++pos2].q=z;
				club2[pos2].w=x;
				club2[pos2].e=c;
			}
			else if(c>=z&&c>=x)
			{
				club3[++pos3].q=z;
				club3[pos3].w=x;
				club3[pos3].e=c;
			}
		}
		if(pos1>n/2)
		{
			sort(club1+1,club1+pos1+1,cmp1);
			int pos=n/2;
			for(int i=pos1;i>=pos+1;i--)
			{
				if(pos2<n/2&&pos3<n/2)
				{
					if(club1[i].q-club1[i].w>club1[i].q-club1[i].e)
					{
						club3[++pos3]=club1[pos1--];
					}
					else
					{
						club2[++pos2]=club1[pos1--];
					}
				}
				else if(pos2<n/2&&pos3>=n/2)
				{
					club2[++pos2]=club1[pos1--];
				}
				else if(pos2>=n/2&&pos3<n/2)
				{
					club3[++pos3]=club1[pos1--];
				}
			}
		}
		if(pos2>n/2)
		{
			sort(club2+1,club2+pos2+1,cmp2);
			int pos=n/2;
			for(int i=pos2;i>=pos+1;i--)
			{
				if(pos1<n/2&&pos3<n/2)
				{
					if(club2[i].w-club2[i].e<club2[i].w-club2[i].q)
					{
						club3[++pos3]=club2[pos1--];
					}
					else
					{
						club1[++pos1]=club2[pos2--];
					}
				}
				else if(pos1<n/2&&pos3>=n/2)
				{
					club1[++pos1]=club2[pos2--];
				}
				else if(pos1>=n/2&&pos3<n/2)
				{
					club3[++pos3]=club2[pos2--];
				}
			}
		}
		if(pos3>n/2)
		{
			sort(club3+1,club3+pos3+1,cmp3);
			int pos=n/2;
			for(int i=pos3;i>=pos+1;i--)
			{
				if(pos2<n/2&&pos1<n/2)
				{
					if(club3[i].e-club3[i].q<club3[i].e-club3[i].w)
					{
						club1[++pos1]=club3[pos3--];
					}
					else
					{
						club2[++pos2]=club3[pos3--];
					}
				}
				else if(pos2<n/2&&pos1>=n/2)
				{
					club2[++pos2]=club3[pos3--];
				}
				else if(pos2>=n/2&&pos1<n/2)
				{
					club1[++pos1]=club3[pos3--];
				}
			}
		}
		long long sum=0;
		for(int i=1;i<=pos1;i++)
		{
			sum+=club1[i].q;
		}
		for(int i=1;i<=pos2;i++)
		{
			sum+=club2[i].w;
		}
		for(int i=1;i<=pos3;i++)
		{
			sum+=club3[i].e;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
